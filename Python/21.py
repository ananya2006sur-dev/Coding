def func(l):
    product = 1
    for num in l:
        product *= num 
    return [sum(l)] + l[-2:0:-1] + [product] 

l = [6, 4, 1, 9, 7]
print(func(l))

l = [1, 2]
print(l[-2:0:-1])  