import cv2
import matplotlib.pyplot as plt

img = cv2.imread("Lena.png", cv2.IMREAD_GRAYSCALE)

# https://docs.opencv.org/3.4/d1/db7/tutorial_py_histogram_begins.html
histogram = cv2.calcHist([img], [0], None, [256], [0, 256])

plt.hist(img.ravel(), 256, [0, 256])
plt.show()

equalized_img = cv2.equalizeHist(img)
equalized_histogram = cv2.calcHist([equalized_img], [0], None, [256], [0, 256])

plt.hist(equalized_img.ravel(), 256, [0, 256])
plt.show()
cv2.imshow("Equalized Image", equalized_img)

while True:
    if cv2.waitKey(0) & 0xFF == ord('q'):
        break
cv2.destroyAllWindows()
