import cv2
import numpy as np
from matplotlib import pyplot as plt


# task 1
def stdev_filter(img, ksize):
    rows, cols = img.shape
    output = np.zeros_like(img)

    for i in range(rows):
        for j in range(cols):
            start_i = max(0, i - ksize // 2)
            end_i = min(rows, i + ksize // 2 + 1)
            start_j = max(0, j - ksize // 2)
            end_j = min(cols, j + ksize // 2 + 1)

            region = img[start_i:end_i, start_j:end_j]
            output[i, j] = np.std(region)
    return output


ksize = 5

img = cv2.imread("practice_images/practice_images/sudoku.png", cv2.IMREAD_GRAYSCALE)
img_std = stdev_filter(img, ksize)

fig1, ax = plt.subplots(ncols=2, figsize=(21, 21))
ax[0].imshow(img, cmap='gray')
ax[0].set_title('Original image')
ax[1].imshow(img_std, cmap='gray')
ax[1].set_title('STD filtered image')

plt.show()

#task 2 - adaptive thresholding
no_thresholding_image = cv2.imread("practice_images/practice_images/sudoku.png", cv2.IMREAD_GRAYSCALE)


def manual_thresholding(image, max_value, threshold_type, block_size, constant):
    processed = np.zeros_like(image)
    height, width = image.shape

    block_step = block_size // 2  # integer division

    for x in range(height):
        for y in range(width):
            neighbour_max_x = x + block_step + 1
            neighbour_max_y = y + block_step + 1

            neighbour_min_x = max(x - block_step, 0)
            neighbour_min_y = max(y - block_step, 0)

            block = image[neighbour_min_x:neighbour_max_x, neighbour_min_y:neighbour_max_y]
            mean = np.mean(block) - constant

            if threshold_type == cv2.THRESH_BINARY:
                if image[x, y] > mean:
                    processed[x, y] = max_value
                else:
                    processed[x, y] = 0
            if threshold_type == cv2.THRESH_BINARY_INV:
                if image[x, y] > mean:
                    processed[x, y] = 0
                else:
                    processed[x, y] = max_value
    return processed


adaptive_thresholding_image = cv2.adaptiveThreshold(no_thresholding_image, 255,
                                                    cv2.ADAPTIVE_THRESH_MEAN_C,
                                                    cv2.THRESH_BINARY, 11, 7)

manual_thresholding_image = manual_thresholding(no_thresholding_image, 255,
                                                cv2.THRESH_BINARY, 11, 7)

fig2, ax = plt.subplots(ncols=3, figsize=(21, 21))
ax[0].imshow(no_thresholding_image, cmap='gray')
ax[0].set_title('No thresholding image')
ax[1].imshow(adaptive_thresholding_image, cmap='gray')
ax[1].set_title('Mean thresholding image (opencv)')
ax[2].imshow(manual_thresholding_image, cmap='gray')
ax[2].set_title('Mean thresholding image (manual)')

plt.show()

# task 3 - find letters

img = cv2.imread("practice_images/practice_images/alphabet.png", cv2.IMREAD_GRAYSCALE)
_, img = cv2.threshold(img, 127, 255, cv2.THRESH_BINARY_INV)

contours, hierarchy = cv2.findContours(img, cv2.RETR_CCOMP, cv2.CHAIN_APPROX_SIMPLE)

img_rgb = cv2.cvtColor(img, cv2.COLOR_GRAY2RGB)
for i in range(len(contours)):
    if hierarchy[0][i][2] != -1:
        x, y, w, h = cv2.boundingRect(contours[i])
        cv2.rectangle(img_rgb, (x, y), (x+w, y+h), (0, 255, 0), 2)

fig3, ax = plt.subplots()
ax.imshow(img_rgb, cmap="gray")

plt.show()

all_figures = [fig1, fig2, fig3]

for i, fig in enumerate(all_figures):
    fig.savefig(f"output_image_{i}.png")


