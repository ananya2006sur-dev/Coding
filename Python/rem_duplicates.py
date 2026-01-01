l = [1, 2, 2, 3, 4, 4, 5]
#if time complexity is more important than space complexity:
seen = set()
new = []
for num in l: #O(n) 
    if num not in seen: #O(1)
        seen.add(num) #O(1)
        new.append(num) #O(1)
print(new)  
#Total time complexity = O(n) 

#if space complexity is more important than time complexity:
i = 0
while i < len(l): #O(n) 
    if l[i] in l[i + 1:]: #O(n)
        l.pop(i) #O(n) 
    else:
        i += 1 #O(1) 
print(l) 
#Total time complexity = O(n^2)