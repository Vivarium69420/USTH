import cv2
import wait_img as wi
import numpy as np

def salt_pepper_noise(image, prob):
    """
    Sprinkle salt and pepper noise on the image
    :param image: image to be processed
    :param prob: probability of the noise to be added
    :return: image with salt and pepper noise
    """
    threshold = 1 - prob
    for row in range(image.shape[0]):
        for col in range(image.shape[1]):
            random = np.random.random()
            if random < prob:
                image[row][col] = 0
            elif random > threshold:
                image[row][col] = 255
            else:
                pass
    return image

def gaussian_noise(image, var):
    """
    Add gaussian noise to the image
    :param image: image to be processed
    :param var: variance of the gaussian noise
    :return: image with gaussian noise

    Note: A larger standard deviation corresponds to higher intensity noise, 
    resulting in more noticeable fluctuations in the pixel values.
    """
    mean = 0    
    sigma = var ** 0.5
    gauss = np.random.normal(mean, sigma, image.shape)
    gauss = gauss.reshape(image.shape)
    image = image + gauss
    image = np.clip(image, 0, 255).astype(np.uint8)
    return image 

def periodic_noise(image, amp, freq):
    """
    Add periodic noise to the image
    :param image: image to be processed
    :param amp: amplitude of the periodic noise
    :param freq: frequency of the periodic noise
    :return: image with periodic noise
    """
    for row in range(image.shape[0]):
        for col in range(image.shape[1]):
            image[row][col] = image[row][col] + amp * np.sin(2 * np.pi * freq * row)
    image = np.clip(image, 0, 255).astype(np.uint8)
    return image 

if __name__ == "__main__":
    img = cv2.imread('Lena.png')

    flavored_Lena = salt_pepper_noise(img, 0.05)
    cv2.imshow('Flavored Lena', flavored_Lena)

    gaussian_Lena = gaussian_noise(img, 0)
    cv2.imshow('Gaussian Lena', gaussian_Lena)

    periodic_Lena = periodic_noise(img, 50, 0.1)
    cv2.imshow('Periodic Lena', periodic_Lena)


    wi.wait() 
    
