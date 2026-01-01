def is_palindrome(s):
    cleaned = ''.join(c.lower() for c in s if c.isalnum()) #ignore punctuation and spaces
    #since c is a single character, time complexity of c.lower() is O(1)
    #for loop - O(n)
    #join - O(n)
    #total time complexity - O(n) + O(n) + O(n) = O(3n) = O(n)
    return cleaned == cleaned[::-1] #O(n) for comparison and O(n) for slicing thus O(2n) = O(n)
#Total time complexity of is_palindrome function is O(n) + O(n) = O(2n) = O(n) which is linear time complexity

print(is_palindrome("A man a plan a canal Panama")) 
