import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

# ====== Part 5: Normal Equation method with Regularization ====== #
# Load the advertising dataset
data = pd.read_csv("Advertising.csv")
X = data[['TV', 'radio', 'newspaper']].values
y = data['sales'].values

# Regularization parameter
lambd = 0.2

# Add a column of ones for the intercept
X = np.column_stack((np.ones(len(X)), X))

# Calculate the coefficients using the normal equation
theta = np.linalg.inv(X.T.dot(X) + lambd * np.identity(len(X.T))).dot(X.T).dot(y)

# Calculate R^2
r_square = 1 - (np.sum((y - X.dot(theta)) ** 2) / np.sum((y - y.mean()) ** 2))

# Print the coefficients obtained by the normal equation
print("Coefficients (Normal Equation with Regularization):", theta)
print("R^2:", r_square)
