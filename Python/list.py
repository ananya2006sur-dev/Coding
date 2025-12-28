fname = input("Enter the file name: ")
fhand = open(fname) 

many = {}

for line in fhand:
    line = line.rstrip()
    wds = line.split()
    
    for w in wds:
        w = w.strip(".,!?:")
        many[w] = many.get(w, 0) + 1
    
print(many)