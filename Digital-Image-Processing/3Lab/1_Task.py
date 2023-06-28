import cv2
import wait_img as wi

# Read image
img = cv2.imread("incredible.jpg", cv2.IMREAD_GRAYSCALE)

# apply laplacian filter
lap = cv2.Laplacian(img, cv2.CV_64F)
so = cv2.Sobel(img, cv2.CV_64F, 1, 0, ksize=5)

# display image
cv2.imshow("Original", img)
cv2.imshow("Laplacian", lap)
cv2.imshow("Sobel", so)

wi.wait()
