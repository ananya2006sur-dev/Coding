def func(l):
    return [num for num in l if num > 10 and num % 3 == 0]

l = [3, 12, 15, 7, 9, 18, 5, 21]
print(func(l)) 