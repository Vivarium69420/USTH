import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

data = pd.read_csv('marks.csv')
# get the data from the csv file
X = data.iloc[:, :-1].values
y = data.iloc[:, -1].values

# plot the data after reshaping it
plt.scatter(X.reshape(-1, 1), y.reshape(-1,1), color='blue')
plt.xlabel('Marks')
plt.ylabel('Chance of Admit')
plt.show()
