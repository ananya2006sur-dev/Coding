keys = ['a', 'b', 'c']
values = [1, 2, 3]

d = {}
print(d)
d = {keys[i] : values[i] for i in range(len(keys))} 
print(d)

d = {}
print(d) 
zipped = zip(keys, values)
d = dict(zipped)
print(d)
    