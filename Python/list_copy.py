import copy
a = [6, 4, [1, 2, 3], 9, 7]
b = copy.deepcopy(a)
print(a)
print(b)
b[2][1] = 10 
print(a)
print(b) 