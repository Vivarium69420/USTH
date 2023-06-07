import cv2 
import wait_img as wi

img = cv2.imread('Lena.png')
cv2.imshow('Lena', img)

blur_Lena = cv2.blur(img, (5, 5))
gaussianBlur_Lena = cv2.GaussianBlur(img, (5, 5), 0)
medianBlur_Lena = cv2.medianBlur(img, 5)

cv2.imshow('Blur Lena', blur_Lena)
cv2.imshow('Gaussian Blur Lena', gaussianBlur_Lena)
cv2.imshow('Median Blur Lena', medianBlur_Lena)

wi.wait()
