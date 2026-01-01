from collections import Counter

def are_anagrams(str1, str2):
    s1 = ''.join(str1.lower().split())
    s2 = ''.join(str2.lower().split())
    return Counter(s1) == Counter(s2)
        
 
print(are_anagrams("aabb", "aba"))