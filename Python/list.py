fhand = open('sun.txt')
counts = {}
for line in fhand:
    words = line.split() 
    for word in words:
        word = word.strip('.,?!:;')
        counts[word] = counts.get(word, 0) + 1 

counts_rev = sorted([(count, wd) for wd, count in counts.items()], reverse = True) 
print(counts_rev)