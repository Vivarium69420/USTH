import cv2
import wait_img as wi

# Read the noisy image
salt_pepper_Lena = cv2.imread('./outputs/Salt and Pepper Noise Lena.png')
gaussian_Lena = cv2.imread('./outputs/Gaussian Noise Lena.png')
periodic_Lena = cv2.imread('./outputs/Periodic Noise Lena.png')

# Apply average filter
average_salt_pepper_Lena = cv2.blur(salt_pepper_Lena, (5, 5))
average_gaussian_Lena = cv2.blur(gaussian_Lena, (5, 5))
average_periodic_Lena = cv2.blur(periodic_Lena, (5, 5))

# Apply the median filter
median_salt_pepper_Lena = cv2.medianBlur(salt_pepper_Lena, 5)
median_gaussian_Lena = cv2.medianBlur(gaussian_Lena, 5)
median_periodic_Lena = cv2.medianBlur(periodic_Lena, 5)

# Apply the Gaussian filter
gaussian_salt_pepper_Lena = cv2.GaussianBlur(salt_pepper_Lena, (5, 5), 0)
gaussian_gaussian_Lena = cv2.GaussianBlur(gaussian_Lena, (5, 5), 0)
gaussian_periodic_Lena = cv2.GaussianBlur(periodic_Lena, (5, 5), 0)

# Show the images 
# cv2.imshow('Average filter Salt and Pepper Lena', average_salt_pepper_Lena)
# cv2.imshow('Average filter Gaussian Lena', average_gaussian_Lena)
# cv2.imshow('Average filter Periodic Lena', average_periodic_Lena)

# cv2.imshow('Median filter Salt and Pepper Lena', median_salt_pepper_Lena)
# cv2.imshow('Median filter Gaussian Lena', median_gaussian_Lena)
# cv2.imshow('Median filter Periodic Lena', median_periodic_Lena)

cv2.imshow('Gaussian filter Salt and Pepper Lena', gaussian_salt_pepper_Lena)
cv2.imshow('Gaussian filter Gaussian Lena', gaussian_gaussian_Lena)
cv2.imshow('Gaussian filter Periodic Lena', gaussian_periodic_Lena)

wi.wait()
