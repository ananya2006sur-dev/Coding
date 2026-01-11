def is_palindrome(s):
    length = len(s) 
    if length <= 1:
        return None
    for i in range(length//2):
        if s[i] != s[length - i - 1]:
            return False 
    return True 

