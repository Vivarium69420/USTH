import cv2
import numpy as np
import matplotlib.pyplot as plt
import wait_img as wi

# Load the periocic noisy image
img = cv2.imread("./outputs/Periodic Noise Lena.png")

# Clip the image to 0-255
img = np.clip(img, 0, 255)

# Transform to frequency domain
f = np.fft.fft2(img)
fshift = np.fft.fftshift(f)

# clip again and set to int
fshift = np.clip(fshift, 0, 255)

# plot the frequency domain should show in black and white
plt.figure()
plt.imshow(np.log(np.abs(fshift)))
plt.title("Frequency domain")
plt.show()

# perform frequency filtering
# create a mask
mask = np.zeros(img.shape)
mask[200:300, 200:300] = 1

# apply the mask
fshift = fshift * mask

# plot the frequency domain
plt.figure()
plt.imshow(np.log(np.abs(fshift)))
plt.title("Frequency domain after filtering")
plt.show()

# inverse Transform
f_ishift = np.fft.ifftshift(fshift)
img_back = np.fft.ifft2(f_ishift)

# # clip again and set to int
img_back = np.uint8(img_back)
img_back = np.clip(img_back, 0, 255)

# plot the image
plt.figure()
plt.imshow(img_back)
plt.title("Image after filtering")
plt.show()
