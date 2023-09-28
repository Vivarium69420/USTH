import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LogisticRegression

# ===== Part 1: Logistic Regression ===== #

data = pd.read_csv('marks.csv')
# get the data from the csv file
X = data.iloc[:, :-1].values
y = data.iloc[:, -1].values

# hyperparameters
alpha = 0.001
num_iterations = 800000
lambd = 0.1

# initialize coefficients
theta = np.zeros(3)

# add a column of ones for the intercept
X = np.column_stack((np.ones(len(X)), X))

# initialize a list to store the cost function values after each iteration
cost_history = []

# Sigmod function
def sigmoid(z):
    return 1 / (1 + np.exp(-z))

# function to calculate the cost (MSE)
def compute_cost(X, y, theta):
    m = len(y)
    y_pred = sigmoid(X.dot(theta))
    cost = np.sum(-y * np.log(y_pred) - (1 - y) * np.log(1 - y_pred)) / m
    return cost

# function to calculate the F1 score
def compute_f1_score(X, y, theta):
    y_pred = sigmoid(X.dot(theta))
    y_pred = np.where(y_pred >= 0.5, 1, 0)
    tp = np.sum((y == 1) & (y_pred == 1))
    fp = np.sum((y == 0) & (y_pred == 1))
    fn = np.sum((y == 1) & (y_pred == 0))
    precision = tp / (tp + fp)
    recall = tp / (tp + fn)
    f1_score = 2 * precision * recall / (precision + recall)
    return f1_score

# predict function
def predict(X, theta):
    y_pred = sigmoid(X.dot(theta))
    y_pred = np.where(y_pred >= 0.5, 1, 0)
    return y_pred

# perform gradient descent
def gradient_descent(X, y, theta, alpha, num_iterations):
    for iteration in range(num_iterations):
        error = sigmoid(X.dot(theta)) - y
        gradient = X.T.dot(error) / len(X)
        theta -= alpha * gradient
        cost = compute_cost(X, y, theta)
        cost_history.append(cost)
        f1_score = compute_f1_score(X, y, theta)
        # print("Iteration:", iteration, "Cost:", cost, "F1 score:", f1_score)
        # print("Coefficients:", theta)
    return theta, cost_history, f1_score

# perform gradient descent with regularization (L2)
def gradient_descent_regularization(X, y, theta, alpha, num_iterations, lambd):
    for iteration in range(num_iterations):
        error = sigmoid(X.dot(theta)) - y
        gradient = X.T.dot(error) / len(X)
        theta[0] -= alpha * gradient[0]
        theta[1:] = (1 - alpha * lambd / len(X)) * theta[1:] - alpha * gradient[1:]
        cost = compute_cost(X, y, theta)
        cost_history.append(cost)
        f1_score = compute_f1_score(X, y, theta)
        print("Iteration:", iteration, "Cost:", cost, "F1 score:", f1_score)
        # print("Coefficients:", theta)
    return theta, cost_history, f1_score

# # plot the cost function as a function of the iteration
# plt.plot(range(num_iterations), cost_history)
# plt.xlabel("Iteration")
# plt.ylabel("Cost")
# plt.title("Cost Function vs. Iteration")
# plt.show()

# Test the functions
# theta, cost_history, f1_score = gradient_descent(X, y, theta, alpha, num_iterations)
theta, cost_history, f1_score = gradient_descent_regularization(X, y, theta, alpha, num_iterations, lambd)

# print the final coefficients
print("Final coefficients:", theta)
print("F1 score:", f1_score)

# Compare with scikit-learn's LogisticRegression
reg = LogisticRegression()
reg.fit(X, y)
print("Scikit-learn's coefficients:", reg.coef_)
print("Scikit-learn's intercept:", reg.intercept_)
print("Scikit-learn's F1 score:", reg.score(X, y))

# Try to predict the result for a student who got 45 in the first exam and 85 in the second exam
X_test = np.array([1, 45, 85])
y_pred = predict(X_test, theta)
print("Predicted result:", y_pred)

reg.predict(X_test.reshape(1, -1))
print("Scikit-learn's predicted result:", reg.predict(X_test.reshape(1, -1)))
