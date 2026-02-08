l1 = [6, 4, 1, 9, 7]
l2 = [3, 2, 1, 8, 7]
sorted_l1 = sorted(l1) #O(nlogn)
sorted_l2 = sorted(l2) #O(nlogn)
i = 0
j = 0
common_elems = []
while i < len(l1) and j < len(l2): #O(max(len(l1), len(l2))) = O(n) 
    if sorted_l2[j] < sorted_l1[i]:
        j += 1
    elif sorted_l2[j] > sorted_l1[i]:
        i += 1
    else:
        common_elems.append(sorted_l1[i])
        i += 1
        j += 1
print(common_elems) 
#Total time complexity = O(nlogn)

d1 = {}
d2 = {}
for key1 in l1: #O(n)
    d1.setdefault(key1, None)
for key2 in l2: #O(n) 
    d2.setdefault(key2, None)
    
common_elems = []
for key in d1: #O(n)
    if key in d2:
        common_elems.append(key)

print(common_elems)
#Total time complexity = O(n)