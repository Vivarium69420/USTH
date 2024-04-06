# Square-and-Multiply Algorithm for Modular Exponentiation

x = 856  # base
e = 25  # exponent
n = 7  # modulus


# Convert exponent to binary
def binary(e):
    return bin(e)[2:]


# Square-and-Multiply Algorithm
def square_multiply(x, e, n):
    y = 1
    for i in binary(e):
        y = y**2 % n
        if i == "1":
            y = y * x % n
    return y


# Print result
print(square_multiply(x, e, n))
# result = 2


# ========================= #
# Manually check the result #
# ========================= #

"""
(856)^25 mod 7

25 = (11001)_2 = (h4 h3 h2 h1 h0)_2
h4 = 1: (856) mod 7 === 2
h3 = 1: (856)^2 mod 7 === (2)(2) mod 7 === 4
        (856)^2 (856) mod 7 === (4)(2) mod 7 === 1
h2 = 0: (856^3)^2 mod 7 === (1)(1) mod 7 === 1
h1 = 0: (856^6)^2 mod 7 === (1)(1) mod 7 === 1
h0 = 1: (856^12)^2 mod 7 === (1)(1) mod 7 === 1
        (856^24)(856) mod 7 === (1)(2) mod 7 === 2

result = 2
"""
