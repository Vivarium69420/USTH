# Implementing the A5/1 Cipher Algorithm


def majority(x, y, z):
    if x + y + z > 1:
        return 1
    else:
        return 0


def shiftX(X):
    temp = (X[13] + X[16] + X[17] + X[18]) % 2
    i = 18
    while i > 0:
        X[i] = X[i - 1]
        i -= 1

    X[0] = temp


def shiftY(Y):
    temp = (Y[20] + Y[21]) % 2
    i = 21
    while i > 0:
        Y[i] = Y[i - 1]
        i -= 1

    Y[0] = temp


def shiftZ(Z):
    temp = (Z[7] + Z[20] + Z[21] + Z[22]) % 2
    i = 22
    while i > 0:
        Z[i] = Z[i - 1]
        i -= 1
    Z[0] = temp


def keyStream(x, y, z):
    return (x + y + z) % 2


X = [1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1]
Y = [1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1]
Z = [1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0]

n = 10
for i in range(n):
    m = majority(X[8], Y[10], Z[10])

    if X[8] == m:
        shiftX(X)

    if Y[10] == m:
        shiftY(Y)

    if Z[10] == m:
        shiftZ(Z)

    print(keyStream(X[18], Y[21], Z[22]), end="")
print()
print(X)
print(Y)
print(Z)
