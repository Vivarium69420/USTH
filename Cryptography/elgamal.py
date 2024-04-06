# Elgamal Signature Scheme
d = int(input("d: "))
p = int(input("p: "))
alpha = int(input("alpha: "))

# check if beta is provided if not calculate it
beta = int(input("beta: "))
if beta == 0:
    beta = (alpha**d) % p
    print("beta: ", beta)


print("Public key: ", (p, alpha, beta))
print("Private key: ", d)


def modinv(a, m):
    for i in range(1, m):
        if (a * i) % m == 1:
            return i


def calculate_signature(x, k):
    r = (alpha**k) % p
    s = ((x - d * r) * modinv(k, p - 1)) % (p - 1)
    return r, s


def verify_signature(x, r, s):
    if (alpha**x) % p == ((beta**r) * (r**s)) % p:
        return True
    else:
        return False


while True:
    choice = int(
        input(
            "Calculate signature or verify signature? (1 for calculate, 2 for verify): "
        )
    )
    if choice == 1:
        x = int(input("x: "))
        k = int(input("k: "))
        print("Signature: ", calculate_signature(x, k))

    else:
        x = int(input("x: "))
        r = int(input("r: "))
        s = int(input("s: "))
        print("Signature is valid: ", verify_signature(x, r, s))

    print("\n")

    resume = int(input("Do you want to continue? (1 for yes, 2 for no): "))
    if resume == 2:
        break
