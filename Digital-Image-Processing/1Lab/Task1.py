import cv2

# Read the image
img = cv2.imread("Lena.png")

cv2.imshow("Title", img)

# wait forever until click 'q' to quit
while True:
    if cv2.waitKey(0) & 0xFF == ord('q'):
        break
cv2.destroyAllWindows()
