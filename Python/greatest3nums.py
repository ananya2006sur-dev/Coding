#!/usr/bin/env python3

number1 = int(input("First Number: "))
number2 = int(input("Second Number: "))
number3 = int(input("Third Number: "))
greatest = number1
if number1 < number2:
	greatest = number2
if greatest < number3:
	greatest = number3
print("Greatest number is " + str(greatest))
