import queue
import matplotlib.pyplot as plt

# getting heuristics from file
def getHeuristics():
    heuristics = {}
    with open(r"D:\NMAI\BTTH_AI_22110130_Week3/heuristics.txt") as f:
        for line in f:
            node_heuristic_val = line.split()
            heuristics[node_heuristic_val[0]] = int(node_heuristic_val[1])
    return heuristics

def getCity():
    city = {}
    citiesCode = {}
    with open(r"D:\NMAI\BTTH_AI_22110130_Week3/cities.txt") as f:
        j = 1
        for line in f:
            node_city_val = line.split()
            city[node_city_val[0]] = [int(node_city_val[1]), int(node_city_val[2])]
            citiesCode[j] = node_city_val[0]
            j += 1
    return city, citiesCode

def createGraph():
    graph = {}
    with open(r"D:\NMAI\BTTH_AI_22110130_Week3/citiesGraph.txt") as file:
        for line in file:
            node_val = line.split()
            if node_val[0] in graph:
                graph[node_val[0]].append([node_val[1], int(node_val[2])])
            else:
                graph[node_val[0]] = [[node_val[1], int(node_val[2])]]
            if node_val[1] in graph:
                graph[node_val[1]].append([node_val[0], int(node_val[2])])
            else:
                graph[node_val[1]] = [[node_val[0], int(node_val[2])]]
    return graph

def GBFS(startNode, heuristics, graph, goalNode):
    priorityQueue = queue.PriorityQueue()
    priorityQueue.put((heuristics[startNode], startNode))
    parent = {startNode: None}  # Track the parent of each node to reconstruct the path

    while not priorityQueue.empty():
        current = priorityQueue.get()[1]

        if current == goalNode:
            break

        for neighbor in graph[current]:
            if neighbor[0] not in parent:  # Only consider unvisited nodes
                parent[neighbor[0]] = current
                priorityQueue.put((heuristics[neighbor[0]], neighbor[0]))

    # Reconstruct path from goal to start
    path = []
    while current is not None:
        path.append(current)
        current = parent[current]
    path.reverse()  # Reverse to get path from start to goal

    return path

def Astar(startNode, heuristics, graph, goalNode):
    priorityQueue = queue.PriorityQueue()
    priorityQueue.put((heuristics[startNode], startNode, 0))
    parent = {startNode: None}  # Track the parent of each node to reconstruct the path
    cost_so_far = {startNode: 0}  # Track cost to each node

    while not priorityQueue.empty():
        _, current, current_cost = priorityQueue.get()

        if current == goalNode:
            break

        for neighbor in graph[current]:
            new_cost = current_cost + neighbor[1]
            if neighbor[0] not in cost_so_far or new_cost < cost_so_far[neighbor[0]]:
                cost_so_far[neighbor[0]] = new_cost
                priorityQueue.put((new_cost + heuristics[neighbor[0]], neighbor[0], new_cost))
                parent[neighbor[0]] = current

    # Reconstruct path from goal to start
    path = []
    while current is not None:
        path.append(current)
        current = parent[current]
    path.reverse()  # Reverse to get path from start to goal

    return path

def drawMap(city, gbfs, astar, graph):
    for i, j in city.items():
        plt.plot(j[0], j[1], "ro")
        plt.annotate(i, (j[0] + 5, j[1]))

        for k in graph[i]:
            n = city[k[0]]
            plt.plot([j[0], n[0]], [j[1], n[1]], "gray")

    for i in range(len(gbfs) - 1):
        first = city[gbfs[i]]
        second = city[gbfs[i + 1]]
        plt.plot([first[0], second[0]], [first[1], second[1]], "green")

    for i in range(len(astar) - 1):
        first = city[astar[i]]
        second = city[astar[i + 1]]
        plt.plot([first[0], second[0]], [first[1], second[1]], "blue")

    plt.errorbar(1, 1, label="GBFS", color="green")
    plt.errorbar(1, 1, label="ASTAR", color="blue")
    plt.legend(loc="lower left")

    plt.show()

if __name__ == "__main__":
    heuristic = getHeuristics()
    graph = createGraph()
    city, citiesCode = getCity()

    for i, j in citiesCode.items():
        print(i, j)

    while True:
        inputCode1 = int(input("Start Node: "))
        inputCode2 = int(input("Goal Node: "))

        if inputCode1 == 0 or inputCode2 == 0:
            break

        startCity = citiesCode[inputCode1]
        endCity = citiesCode[inputCode2]

        gbfs = GBFS(startCity, heuristic, graph, endCity)
        astar = Astar(startCity, heuristic, graph, endCity)
        print("GBFS =>", gbfs)
        print("ASTAR =>", astar)

        drawMap(city, gbfs, astar, graph)

