import pygame
from pygame.locals import *
from OpenGL.GL import *
from OpenGL.GLU import *
import numpy as np
import math
import random
from scipy.spatial.transform import Rotation as R

# =========================
# GLOBAL SETTINGS
# =========================
WIDTH, HEIGHT = 1280, 720
WINDOW_NAME = 'Rubik Cube Demo'
TARGET_FPS = 60

WHITE = (255,255,255)
RED = (137,18,20)
BLUE = (13,72,172)
ORANGE = (255,85,37)
GREEN = (25,155,76)
YELLOW = (254,213,47)
ALL_COLORS = np.array([WHITE, GREEN, YELLOW, BLUE, RED, ORANGE])/255

camera_angle = 0  # auto rotate
camera_dist = 80

# =========================
# PARTICLE SYSTEM
# =========================
class Particle:
    def __init__(self, position):
        self.position = np.array(position, dtype=float)
        self.velocity = np.random.uniform(-0.5,0.5,3)
        self.lifetime = random.randint(20,50)

    def update(self):
        self.position += self.velocity
        self.velocity *= 0.95
        self.lifetime -= 1

    def draw(self):
        glPointSize(3)
        glBegin(GL_POINTS)
        glColor4f(1,1,0,max(self.lifetime/50,0))
        glVertex3fv(self.position)
        glEnd()

particles = []

def spawn_particles(cubes_layer):
    for cube in cubes_layer:
        pos = cube.position
        for _ in range(5):
            particles.append(Particle(pos))

def update_particles():
    global particles
    for p in particles[:]:
        p.update()
        if p.lifetime<=0:
            particles.remove(p)

def draw_particles():
    glDisable(GL_LIGHTING)
    for p in particles:
        p.draw()
    glEnable(GL_LIGHTING)

# =========================
# CUBE CLASS
# =========================
class Cube:
    def __init__(self, position, colors, virtual=False):
        self.virtual = virtual
        self.position = np.array(position, dtype=float)
        self.colors = colors
        self.rotation_axis = np.array((1,0,0))
        self.rotation_angle = 0
        self.offset = position
        self.vertices = (
            (1, -1, -1),
            (1, 1, -1),
            (-1, 1, -1),
            (-1, -1, -1),
            (1, -1, 1),
            (1, 1, 1),
            (-1, -1, 1),
            (-1, 1, 1)
        )
        self.surfaces = (
            (0, 1, 2, 3),
            (3, 2, 7, 6),
            (6, 7, 5, 4),
            (4, 5, 1, 0),
            (1, 5, 7, 2),
            (4, 0, 3, 6)
        )
        if not virtual:
            self.create_display_list()

    def draw(self):
        if self.virtual:
            return
        glPushMatrix()
        glTranslatef(*self.position)
        glRotatef(self.rotation_angle, *self.rotation_axis)
        glCallList(self.display_list)
        glPopMatrix()

    def rotate(self, angle, axis, rotation_point):
        if self.virtual:
            return
        translation_matrix = np.identity(4)
        translation_matrix[:3,3] = -np.array(rotation_point)
        rotation_matrix = np.identity(4)
        quat = np.array([np.cos(np.radians(angle/2))] + list(np.sin(np.radians(angle/2))*np.array(axis)))
        rotation_matrix[:3,:3] = self.quaternion_to_matrix(quat)
        inverse_translation = np.identity(4)
        inverse_translation[:3,3] = np.array(rotation_point)
        transform = inverse_translation @ rotation_matrix @ translation_matrix
        self.position = transform[:3,:3] @ self.position + transform[:3,3]

    def create_display_list(self):
        self.display_list = glGenLists(1)
        glNewList(self.display_list, GL_COMPILE)
        glBegin(GL_QUADS)
        for i,surf in enumerate(self.surfaces):
            for vertex in surf:
                glColor3fv(self.colors[i])
                glVertex3fv(self.vertices[vertex])
        glEnd()
        glEndList()

    @staticmethod
    def quaternion_to_matrix(quat):
        w,x,y,z = quat
        return np.array([
            [1-2*y**2-2*z**2,2*x*y-2*w*z,2*x*z+2*w*y],
            [2*x*y+2*w*z,1-2*x**2-2*z**2,2*y*z-2*w*x],
            [2*x*z-2*w*y,2*y*z+2*w*x,1-2*x**2-2*y**2]
        ])

# =========================
# MAGIC CUBE CLASS
# =========================
class MagicCube:
    def __init__(self, size, spacing=3, offset=[0,0,0]):
        self.size = size
        self.cubes = []
        colors = ALL_COLORS
        for x in range(size):
            for y in range(size):
                for z in range(size):
                    vflag = not (x==0 or y==0 or z==0 or x==size-1 or y==size-1 or z==size-1)
                    self.cubes.append(Cube(position=(x*spacing+offset[0],y*spacing+offset[1],z*spacing+offset[2]), colors=colors, virtual=vflag))
        self.x_slices = [[x*size*size+y*size+z for y in range(size) for z in range(size)] for x in range(size)]
        self.y_slices = [[x*size*size+y*size+z for x in range(size) for z in range(size)] for y in range(size)]
        self.z_slices = [[x*size*size+y*size+z for x in range(size) for y in range(size)] for z in range(size)]
        self.current_turn = {"turning":False,"totalAngle":0,"currentAngle":0,"axis":None,"slice_no":None,"speed":1}
        self.movesetCounter = 0
        self.testMoveSet = [self.generateRandomMove() for _ in range(50)]
        opposite_moves = [[a,b,-c,-d] for a,b,c,d in reversed(self.testMoveSet)]
        self.testMoveSet.extend(opposite_moves)

    def draw(self):
        for cube in self.cubes:
            cube.draw()

    def rotate_slice(self, axis=(1,0,0), slice_no=0, angle=1):
        cubes_layer = [self.cubes[i] for i in self.get_cubes_in_slice(axis,slice_no)]
        pos_center = (np.array(cubes_layer[0].position)+np.array(cubes_layer[-1].position))/2
        for cube in cubes_layer:
            cube.rotate(angle, axis, pos_center)
        return cubes_layer

    def get_cubes_in_slice(self, axis, slice_no):
        if axis==(1,0,0): return self.x_slices[slice_no]
        if axis==(0,1,0): return self.y_slices[slice_no]
        if axis==(0,0,1): return self.z_slices[slice_no]

    def play_moveset(self):
        if self.movesetCounter<len(self.testMoveSet):
            axis,slice_no,angle,speed = self.testMoveSet[self.movesetCounter]
            self.animated_turn(axis,slice_no,angle,speed)
            self.movesetCounter+=1

    def update(self):
        if self.current_turn["turning"]:
            cubes_layer = self.rotate_slice(self.current_turn["axis"],self.current_turn["slice_no"],self.current_turn["speed"])
            self.current_turn["currentAngle"] += self.current_turn["speed"]
            if abs(self.current_turn["totalAngle"])==180 and abs(self.current_turn["currentAngle"])==abs(self.current_turn["speed"]):
                spawn_particles(cubes_layer)
            if abs(self.current_turn["currentAngle"])>=abs(self.current_turn["totalAngle"]):
                self.current_turn["turning"]=False
                self.play_moveset()

    def animated_turn(self, axis=(1,0,0), slice_no=0, angle=90, speed=3):
        if not self.current_turn["turning"]:
            self.current_turn={"turning":True,"totalAngle":angle,"currentAngle":0,"axis":axis,"slice_no":slice_no,"speed":speed}

    def generateRandomMove(self):
        axis = random.choice([(1,0,0),(0,1,0),(0,0,1)])
        slice_no = random.randint(0,self.size-1)
        angle = random.choice([-90,90,180])
        speed = 6 if abs(angle)==90 else 12
        return [axis,slice_no,angle,speed]

# =========================
# OPENGL HELPERS
# =========================
def setup_lighting():
    glEnable(GL_LIGHTING)
    glEnable(GL_LIGHT0)
    glLightfv(GL_LIGHT0, GL_POSITION, (50,50,50,1))
    glLightfv(GL_LIGHT0, GL_DIFFUSE, (1,1,1,1))
    glLightfv(GL_LIGHT0, GL_SPECULAR, (1,1,1,1))
    glEnable(GL_COLOR_MATERIAL)
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE)

def render_floor():
    glDisable(GL_LIGHTING)
    glColor4f(0.2,0.2,0.2,0.3)
    glBegin(GL_QUADS)
    glVertex3f(-100,-1,-100)
    glVertex3f(100,-1,-100)
    glVertex3f(100,-1,100)
    glVertex3f(-100,-1,100)
    glEnd()
    glEnable(GL_LIGHTING)

def draw_glow_edges(cube):
    glDisable(GL_LIGHTING)
    glLineWidth(3)
    glColor3f(1,1,0)
    glPushMatrix()
    glTranslatef(*cube.position)
    glRotatef(cube.rotation_angle,*cube.rotation_axis)
    glBegin(GL_LINES)
    for surf in cube.surfaces:
        for i in range(4):
            v1 = cube.vertices[surf[i]]
            v2 = cube.vertices[surf[(i+1)%4]]
            glVertex3fv(v1)
            glVertex3fv(v2)
    glEnd()
    glPopMatrix()
    glEnable(GL_LIGHTING)

def auto_camera():
    global camera_angle
    camera_angle += 0.3
    glLoadIdentity()
    gluLookAt(
        50*math.sin(math.radians(camera_angle)),30,50*math.cos(math.radians(camera_angle)),
        0,0,0,
        0,1,0
    )

# =========================
# MAIN RENDER
# =========================
def render_frame(cubes,font):
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT)
    setup_lighting()
    render_floor()
    for mcube in cubes:
        for cube in mcube.cubes:
            cube.draw()
            if mcube.current_turn["turning"]:
                draw_glow_edges(cube)
    update_particles()

# =========================
# EVENTS
# =========================
def handle_events(cubes):
    for event in pygame.event.get():
        if event.type==pygame.QUIT:
            pygame.quit()
            quit()

# =========================
# MAIN LOOP
# =========================
def main():
    pygame.init()
    pygame.display.set_mode((WIDTH,HEIGHT), DOUBLEBUF|OPENGL)
    pygame.display.set_caption(WINDOW_NAME)
    clock = pygame.time.Clock()
    font = pygame.font.SysFont("Arial",18)

    glEnable(GL_DEPTH_TEST)
    glEnable(GL_BLEND)
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA)
    glClearColor(0.05,0.05,0.05,1)

    gluPerspective(45,(WIDTH/HEIGHT),0.1,500)
    glTranslatef(0,0,-camera_dist)

    # CREATE MULTIPLE CUBES
    cubes = [
        MagicCube(size=3, offset=(-15,0,0)),
        MagicCube(size=3, offset=(15,0,0)),
        MagicCube(size=2, offset=(0,0,25)),
        MagicCube(size=2, offset=(0,0,-25))
    ]
    for mcube in cubes:
        mcube.play_moveset()

    while True:
        handle_events(cubes)
        auto_camera()
        for mcube in cubes:
            mcube.update()
        render_frame(cubes,font)
        pygame.display.flip()
        clock.tick(TARGET_FPS)

if __name__=="__main__":
    main()
