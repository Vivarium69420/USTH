import cv2

img = cv2.imread('Lena.png')

# apply global thresholding technique to get a binary image
threshold_value = 128
max_value = 255
ret, thresholded_img = cv2.threshold(img, threshold_value, max_value, cv2.THRESH_BINARY)

# display the images
cv2.imshow('Thresholded Image', thresholded_img)

# wait until q key is pressed
while True:
    if cv2.waitKey(0) & 0xFF == ord('q'):
        break
cv2.destroyAllWindows()
