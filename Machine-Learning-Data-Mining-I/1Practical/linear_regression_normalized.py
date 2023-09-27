import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression

# ==================== Part 2+: Linear Regression with Normalized Data ==================== #

# Load the advertising dataset
data = pd.read_csv("Advertising.csv")
X = data[['TV', 'radio', 'newspaper']].values
y = data['sales'].values

# Normalize the features
X = (X - X.mean(axis=0)) / X.std(axis=0)

# Add a column of ones for the intercept
X = np.column_stack((np.ones(len(X)), X))

# Initialize coefficients
theta = np.zeros(4)  # Initialize coefficients for TV, Radio, Newspaper, and the intercept

# Hyperparameters
alpha = 0.01
num_iterations = 1000

# Function to calculate the cost (MSE)
def compute_cost(X, y, theta):
    m = len(y)
    y_pred = X.dot(theta)
    cost = np.sum((y_pred - y) ** 2) / (2 * m)
    return cost

# Initialize a list to store the cost function values after each iteration
cost_history = []

# Perform gradient descent
for iteration in range(num_iterations):
    error = X.dot(theta) - y
    gradient = X.T.dot(error) / len(X)
    theta -= alpha * gradient
    cost = compute_cost(X, y, theta)
    cost_history.append(cost)
    r_square = 1 - (np.sum((y - X.dot(theta)) ** 2) / np.sum((y - y.mean()) ** 2))

# Plot the cost function as a function of the iteration
plt.plot(range(num_iterations), cost_history)
plt.xlabel("Iteration")
plt.ylabel("Cost (MSE)")
plt.title("Cost Function vs. Iteration")
plt.show()

# Print the final coefficients
print("Final coefficients:", theta)
print("R^2:", r_square)

# Compare with scikit-learn's LinearRegression
reg = LinearRegression()
reg.fit(X, y)
print("Scikit-learn's coefficients:", reg.coef_)
print("Scikit-learn's intercept:", reg.intercept_)
print("Scikit-learn's R^2:", reg.score(X, y))