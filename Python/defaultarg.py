def modify(x, y):
    x = x + [4]
    y.append(4)
    
a = [1, 2, 3]
b = [1, 2, 3]
modify(a, b)
print(a)
print(b)