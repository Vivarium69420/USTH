import cv2 
import matplotlib.pyplot as plt
import wait_img as wi

img = cv2.imread('Lena.png')
cv2.imshow('Lena', img)

histogram = cv2.calcHist([img], [0], None, [256], [0, 256])
plt.hist(img.ravel(), 256, [0, 256])
plt.show()

wi.wait()
