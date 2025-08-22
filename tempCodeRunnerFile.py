import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Hàm tham số để nhúng RP^2 vào R^4
def rp2_embedding(u, v):
    x = np.cos(u) * np.cos(v)
    y = np.cos(u) * np.sin(v)
    z = np.sin(u) * np.cos(2 * v)
    w = np.sin(u) * np.sin(2 * v)
    return x, y, z, w

# Tạo lưới cho các tham số u và v
u = np.linspace(0, np.pi, 100)  # u từ 0 đến π (bán cầu)
v = np.linspace(0, np.pi, 100)  # v từ 0 đến π (đối xứng qua trục)
u, v = np.meshgrid(u, v)

# Tính toán tọa độ
x, y, z, w = rp2_embedding(u, v)

# Vẽ hình trong không gian 3D
fig = plt.figure(figsize=(10, 10))
ax = fig.add_subplot(111, projection='3d')

# Sử dụng tọa độ (x, y, z) để chiếu RP^2 từ R^4 xuống R^3
surface = ax.plot_surface(x, y, z, facecolors=plt.cm.plasma((w - w.min()) / (w.max() - w.min())),
                          rstride=3, cstride=3, alpha=0.8, linewidth=0.2, edgecolor='k')

# Hiển thị thanh màu
fig.colorbar(surface, ax=ax, shrink=0.5, aspect=10)

# Cài đặt góc nhìn và nhãn trục
ax.view_init(30, 30)
ax.set_xlabel("X")
ax.set_ylabel("Y")
ax.set_zlabel("Z")
plt.title(r"Embedding of $\mathbb{RP}^2$ from $\mathbb{R}^4$ into $\mathbb{R}^3$", fontsize=14)

# Hiển thị hình ảnh
plt.show()
