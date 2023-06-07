import cv2


img = cv2.imread("Lena.png")
res = cv2.resize(img, (int(img.shape[1]/2), int(img.shape[0]/2)))
cv2.imshow("Resized", res)

while True:
    if cv2.waitKey(0) & 0xFF == ord('q'):
        break
cv2.destroyAllWindows()
