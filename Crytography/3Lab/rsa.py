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


print("\nFirst example: ")

q = int(input("q: "))
p = int(input("p: "))

n = p * q
phi = (p - 1) * (q - 1)
print("Phi: ", phi)

key_choice = int(input("Were you given d or e? (1 for d, 2 for e): "))
if key_choice == 1:
    key = int(input("d: "))
    privateKey = key

    publicExponent = private_key(key, phi)
    print("Public exponent: ", publicExponent)

    print("Public key: ", (n, publicExponent))
    print("Private key: ", privateKey)

    text_choice = int(input("Encrypt or decrypt? (1 for encrypt, 2 for decrypt): "))
    if text_choice == 1:
        plaintext = int(input("Plaintext: "))
        ciphertext = (plaintext**publicExponent) % n
        print("Ciphertext: ", ciphertext)
    else:
        ciphertext = int(input("Ciphertext: "))
        plaintext = (ciphertext**privateKey) % n
        print("Plaintext: ", plaintext)

else:
    key = int(input("e: "))

    if gcd(key, phi) != 1:
        print("e and phi are not coprime")
        exit(0)

    print("Check if e and phi are coprime:", gcd(key, phi) == 1)

    publicExponent = key

    privateKey = private_key(key, phi)

    print("Private key: ", privateKey)
    print("Public key: ", (n, publicExponent))

    text_choice = int(input("Encrypt or decrypt? (1 for encrypt, 2 for decrypt): "))
    if text_choice == 1:
        plaintext = int(input("Plaintext: "))
        ciphertext = (plaintext**publicExponent) % n
        print("Ciphertext: ", ciphertext)
    else:
        ciphertext = int(input("Ciphertext: "))
        plaintext = (ciphertext**privateKey) % n
        print("Plaintext: ", plaintext)
