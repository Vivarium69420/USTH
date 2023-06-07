import cv2
import numpy as np

img = cv2.imread("Lena.png")

# Change the brightness of the image
alpha = 1.0
beta = 100

for x in range(img.shape[0]):
    for y in range(img.shape[1]):
        img[x, y] = np.clip(alpha * img[x, y] + beta, 0, 255)


cv2.imshow("Brightness", img)
while True:
    if cv2.waitKey(0) & 0xFF == ord('q'):
        break
cv2.destroyAllWindows()
