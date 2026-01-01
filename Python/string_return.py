s = "Hello World"
reverse = s[::-1]
print(reverse)
count = 0
for c in s:
    if c.lower() in 'aeiou':
        count += 1 
print("Number of vowels in the string:", count)
split_words = s.split() 
no_space = ''.join(split_words) 
print(no_space) 