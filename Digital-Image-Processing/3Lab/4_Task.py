import cv2
import numpy as np
from matplotlib import pyplot as plt

img = cv2.imread("random_coins.jpg")

# plt will show the image in RGB format while cv2 will show in BGR format
img_color = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
img_gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

# create threshold
ret, thresh = cv2.threshold(img_gray, 0, 255, cv2.THRESH_BINARY_INV + cv2.THRESH_OTSU)

# noise removal
kernal = np.ones((3, 3), np.uint8)
opening = cv2.morphologyEx(thresh, cv2.MORPH_OPEN, kernal, iterations=2)

# sure background area
sure_bg = cv2.dilate(opening, kernal, iterations=3)

# Finding sure foreground area
dist_transform = cv2.distanceTransform(opening, cv2.DIST_L2, 5)
ret, sure_fg = cv2.threshold(dist_transform, 0.7 * dist_transform.max(), 255, 0)

# Finding unknown region
sure_fg = np.uint8(sure_fg)
unknown = cv2.subtract(sure_bg, sure_fg)

# Marker labelling
ret, markers = cv2.connectedComponents(sure_fg)

# Add one to all labels so that sure background is not 0, but 1
markers = markers + 1

# Now, mark the region of unknown with zero
markers[unknown == 255] = 0

# apply watershed
markers = cv2.watershed(img_color, markers)
img_color[markers == -1] = [255, 0, 0]


# show the result
plt.subplot(2, 2, 1), plt.imshow(img_color)
plt.title("Original Image"), plt.xticks([]), plt.yticks([])
plt.subplot(2, 2, 2), plt.imshow(thresh, cmap="gray")
plt.title("Threshold Image"), plt.xticks([]), plt.yticks([])
plt.subplot(2, 2, 3), plt.imshow(sure_fg, cmap="gray")
plt.title("Sure Foreground"), plt.xticks([]), plt.yticks([])
plt.subplot(2, 2, 4), plt.imshow(sure_bg, cmap="gray")
plt.title("Sure Background"), plt.xticks([]), plt.yticks([])
plt.show()
