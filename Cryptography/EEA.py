# Extended Euclidean Algorithm

a = int(input("Enter a: "))
b = int(input("Enter b: "))


def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a


def extended_gcd(a, b):
    x, y = 0, 1
    last_x, last_y = 1, 0
    while b != 0:
        q = a // b
        a, b = b, a % b
        x, last_x = last_x - q * x, x
        y, last_y = last_y - q * y, y
    return last_x, last_y


s, t = extended_gcd(a, b)
print("Bezout coefficients:", s, t)
print("gdc(a,b) = as + bt")
print(gcd(a, b), "=", a, "*", s, "+", b, "*", t)

if gcd(a, b) == 1:
    print("The inverse of", b, "mod", a, "is", t)
