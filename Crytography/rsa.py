# Calcuate the gcd of two numbers
def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a


# Compute the private key
def private_key(e, phi):
    for i in range(1, phi):
        if (e * i) % phi == 1:
            return i


q = 59
p = 47
e = 17

n = p * q
phi = (p - 1) * (q - 1)
print("Phi: ", phi)

publicExponent = gcd(e, phi)
print("Public exponent: ", publicExponent)

print("Public key: ", (n, e))

privateKey = private_key(e, phi)
print("Private key: ", privateKey)

plaintext1 = 600
ciphertext1 = (plaintext1**e) % n

print()
print("Ciphertext: ", ciphertext1)


ciphertext2 = 1424
plaintext2 = (ciphertext2**privateKey) % n
print("Plaintext: ", plaintext2)
