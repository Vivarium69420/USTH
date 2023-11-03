from matplotlib import pyplot as plt
from matplotlib.image import imread

# define local data path
data_path = "../train/"

# plot the first nine images in the dogs dataset
for i in range(9):
    # define subplot
    plt.subplot(330 + 1 + i)
    # define filename
    filename = data_path + "dog." + str(i) + ".jpg"
    # load image pixels
    image = imread(filename)
    # plot raw pixel data
    plt.imshow(image)
# show the figure
plt.show()

# plot the first nine images in the cats dataset
for i in range(9):
    # define subplot
    plt.subplot(330 + 1 + i)
    # define filename
    filename = data_path + "cat." + str(i) + ".jpg"
    # load image pixels
    image = imread(filename)
    # plot raw pixel data
    plt.imshow(image)
# show the figure
plt.show()
