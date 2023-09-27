import pandas as pd
import numpy as np

# ==================== Part 3: Normal Equation Method ==================== #

# Load the advertising dataset
data = pd.read_csv("Advertising.csv")
X = data[['TV', 'radio', 'newspaper']].values
y = data['sales'].values


# Add a column of ones for the intercept term
X = np.column_stack((np.ones(len(X)), X))

# Calculate the coefficients using the normal equation
theta = np.linalg.inv(X.T.dot(X)).dot(X.T).dot(y)

# Calculate R^2
r_square = 1 - (np.sum((y - X.dot(theta)) ** 2) / np.sum((y - y.mean()) ** 2))

# Print the coefficients obtained by the normal equation
print("Coefficients (Normal Equation):", theta)
print("R^2:", r_square)