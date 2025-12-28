num = int(input("Enter an integer: "))
sum_digits = 0
for digit in str(abs(num)):
    sum_digits += int(digit)
print("Sum of the digits:", sum_digits)
for char in "Hello, World!":
    print(char)
for word in "Hello, World!".split():
    print(word)
for sentence in "Hello, World!".split("."):
    print(sentence)
for word in "Hello, World!".split(" "):
    print(word)
for word in "Hello, World!".split(","):
    print(word)
for word in "Hello, World!".split("!"):
    print(word)
for word in "Hello, World!".split("?"):
    print(word)