def func(x, lst=None):  # Use None as default
    if lst is None:
        lst = []         # Create new list each time
    lst.append(x)
    return lst

print(func(1))  # [1]
print(func(2))  # [2]
print(func(3))  # [3]