# Add a commas after every digit in a number
# Example: 1234567 -> 1,2,3,4,5,6,7


def separate_with_commas(number):
    number = str(number)
    for i in range(len(number)):
        if i != len(number) - 1:
            print(number[i] + ", ", end="")
        else:
            print(number[i])


number = input("separate_with_commas(1): ")
separate_with_commas(number)
