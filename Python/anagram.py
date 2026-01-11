from collections import Counter

def are_anagrams(str1, str2):
    s1 = ''.join(str1.lower().split())
    s2 = ''.join(str2.lower().split())
    return Counter(s1) == Counter(s2)
        
 
print(are_anagrams("Listen", "Silent"))

#def are_anagrams_2(str1, str2):
   # s1 = ''.join(str1.lower().split()) #O(n)
   # s2 = ''.join(str2.lower().split()) #O(n) 
   # count1 = {}
   # count2 = {}
  #  if set(s1) != set(s2): #O(n)
   #     return False 
  #  for char in s1: #O(n)
   #     count1[char] = count1.get(char, 0) + 1 
   # for char in s2: #O(n)
    #    count2[char] = count2.get(char, 0) + 1
   # return count1 == count2 #O(n)

#print(are_anagrams_2("Listen", "Silent"))


