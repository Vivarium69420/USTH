from os import listdir
from numpy import asarray, save
from keras.preprocessing.image import load_img, img_to_array

# define local data path
data_path = "../train/"
photos, labels = list(), list()

# enumerate files in the directory
for file in listdir(data_path):
    # determine class
    output = 0.0
    if file.startswith("dog"):
        output = 1.0
    # load image
    photo = load_img(data_path + file, target_size=(200, 200))
    # convert to numpy array
    photo = img_to_array(photo)
    # store
    photos.append(photo)
    labels.append(output)

# convert to a numpy arrays
photos = asarray(photos)
labels = asarray(labels)
print(photos.shape, labels.shape)

# save the reshaped photos
save("dogs_vs_cats_photos.npy", photos)
save("dogs_vs_cats_labels.npy", labels)
