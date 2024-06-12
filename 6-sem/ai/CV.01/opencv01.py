import cv2
import numpy as np
import matplotlib.pyplot as plt

# task 1 - selecting just red peppers

peppers = cv2.imread("C:\\university\\6-sem\\ai\\CV.01\\practice_images\peppers.png")
peppers_rgb = cv2.cvtColor(peppers, cv2.COLOR_BGR2RGB)

lower_red = np.array([120, 0, 0])
higher_red = np.array([255, 60, 60])

peppers_red = peppers_rgb.copy()
red_mask = cv2.inRange(peppers_rgb, lower_red, higher_red)
peppers_red[red_mask == 0] = [255, 255, 255]

fig, ax = plt.subplots(ncols=2, figsize=(21, 21))
ax[0].imshow(peppers_rgb)
ax[1].imshow(peppers_red)
plt.show()

# task 2
cameraman = cv2.imread("C:\\university\\6-sem\\ai\\CV.01\\practice_images\\cameraman.png", cv2.IMREAD_GRAYSCALE)
cameraman_flip_y = cameraman[::-1, :]
cameraman_flip_x = cameraman[:, ::-1]
cameraman_flip_xy = cameraman[::-1, ::-1]

fig2, ax2 = plt.subplots(ncols=4, figsize=(20, 5))
ax2[0].imshow(cameraman, cmap="gray")
ax2[1].imshow(cameraman_flip_x, cmap="gray")
ax2[2].imshow(cameraman_flip_y, cmap="gray")
ax2[3].imshow(cameraman_flip_xy, cmap="gray")
plt.show()

# task 3 - image blending
plane = cv2.imread("C:\\university\\6-sem\\ai\\CV.01\\practice_images\\plane.jpg")[:, :, ::-1]
thunderstorm = cv2.imread("C:\\university\\6-sem\\ai\\CV.01\\practice_images\\thunderstorm.jpg")[:, :, ::-1]

height_thunderstorm, width_thunderstorm = thunderstorm.shape[:2]
resized_plane = cv2.resize(plane, (width_thunderstorm, height_thunderstorm))

alpha = 0.5
beta = 1 - alpha
gamma = 2

thunderstorm_plane = cv2.addWeighted(resized_plane, alpha, thunderstorm, beta, gamma)

fig3, ax = plt.subplots(figsize=(21, 21))
ax.imshow(thunderstorm_plane)
plt.show()

# task 4
leetcode_logo = np.zeros((400, 400, 3), dtype=np.uint8)

rectangle1_vertices = np.array([
    [200, 100],
    [210, 110],
    [140, 180],
    [130, 170]
])
cv2.fillPoly(leetcode_logo, [rectangle1_vertices], (255, 255, 255))

rectangle2_vertices = np.array([
    [140, 200],
    [130, 210],
    [170, 250],
    [180, 240]
])
cv2.fillPoly(leetcode_logo, [rectangle2_vertices], (255, 255, 255))

rectangle3_vertices = np.array([
    [190, 240],
    [200, 250],
    [230, 220],
    [220, 210]
])
cv2.fillPoly(leetcode_logo, [rectangle3_vertices],  (255, 128, 0))

rectangle4_vertices = np.array([
    [190, 130],
    [180, 140],
    [210, 170],
    [220, 160]
])
cv2.fillPoly(leetcode_logo, [rectangle4_vertices],  (255, 128, 0))

rectangle5_vertices = np.array([
    [170, 185],
    [170, 195],
    [240, 195],
    [240, 185]
])
cv2.fillPoly(leetcode_logo, [rectangle5_vertices],  (192, 192, 192))

cv2.ellipse(leetcode_logo, (130, 190), (18, 18), 90, 0, 360, (255, 255, 255), thickness=-1)
cv2.ellipse(leetcode_logo, (185, 250), (14, 14), 90, 0, 360, (255, 128, 0), -1)

cv2.ellipse(leetcode_logo, (225, 215), (7, 7), 90, 0, 360, (255, 128, 0), -1)
cv2.ellipse(leetcode_logo, (215, 165), (7, 7), 90, 0, 360, (255, 128, 0), -1)
cv2.ellipse(leetcode_logo, (205, 105), (7, 7), 90, 0, 360, (255, 255, 255), -1)

cv2.ellipse(leetcode_logo, (170, 190), (5, 5), 90, 0, 360, (192, 192, 192), -1)
cv2.ellipse(leetcode_logo, (240, 190), (5, 5), 90, 0, 360, (192, 192, 192), -1)

cv2.putText(leetcode_logo, "LeetCode", (110, 300), cv2.FONT_ITALIC, 1, (255, 255, 255), 2)
fig4, ax = plt.subplots()
ax.imshow(leetcode_logo)
plt.show()

all_figures = [fig, fig2, fig3, fig4]

for i, fig in enumerate(all_figures):
    fig.savefig(f"output_image_{i}.png")

