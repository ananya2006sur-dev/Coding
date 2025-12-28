num = int(input("Enter an integer: "))
sum_digits = 0
for digit in str(abs(num)):
    sum_digits += int(digit)
print("Sum of the digits:", sum_digits)
