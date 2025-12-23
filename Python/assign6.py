def isPalindrome(s):
    reverse = s[::-1]
    if s == reverse:
        return True
    else:
        return False


first_name1 = input("Enter your first name: ")
print("Your first name is: ", first_name1)
last_name = input("Enter your last name: ")
full_name = first_name1 + " " +  last_name
print("Your full name is: ", full_name)
if 'as' in full_name:
    print("'as' is present in your full name")
else:
    print("'as' is not present in your full name")
first_name2 = input("Enter your friend's first name: ")
if first_name1 == first_name2:
    print("You and your friend have same first name")
else:
    print("You and your friend do not have same first name")


print("Your first name is palindrome: ", isPalindrome(first_name1))
print("'nitin' is palindrome: ", isPalindrome('nitin'))
print("'madam' is palindrome: ", isPalindrome('madam'))
print("'noon' is palindrome: ", isPalindrome('noon'))
print("Your friend's first name is palindrome: ", isPalindrome(first_name2))

