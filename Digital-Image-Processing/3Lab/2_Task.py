import cv2
import wait_img as wi

# Read image
img = cv2.imread("incredible.jpg", cv2.IMREAD_GRAYSCALE)

# apply canny filter
canny = cv2.Canny(img, 100, 200)

# display image
cv2.imshow("Original", img)
cv2.imshow("Canny", canny)

wi.wait()
