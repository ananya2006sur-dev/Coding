size = int(input("Enter the size of the pattern: "))
width = 4*size - 3
for i in range(size):
    l1 = []
    for j in range(size, size - i - 1, -1):
        l1.append(chr(96 + j))
    for k in range(size - i + 1, size + 1):
        l1.append(chr(96 + k))
    s1 = "-".join(l1)
    print(s1.center(width, "-")) 
    
for m in range(size - 1):
    l2 = []
    for n in range(size, m + 1, -1):
        l2.append(chr(96 + n))
    for o in range(m + 3, size + 1):
        l2.append(chr(96 + o))
    s2 = "-".join(l2)
    print(s2.center(width, "-"))