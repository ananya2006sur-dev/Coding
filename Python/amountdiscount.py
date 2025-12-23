#!/usr/bin/env python3

amount = int(input("Enter Amount: "))

if amount > 15000:
	print("Invalid input")

discount = 0

if amount == 15000:
	discount = .15 * amount

if amount > 5000 and amount < 10000:
	discount = .1 * amount

if amount > 2000 and amount < 5000:
	discount = .05 * amount

print("Discount=" + str(discount))