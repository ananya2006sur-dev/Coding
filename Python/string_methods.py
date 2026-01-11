name = "Ananya"
age = 20
city = "Pune"

#f-strings:
print(f"Name: {name}, Age: {age}, City: {city}")

#.format() method:
print("Name: {n}, Age: {a}, City: {c}".format(a = age, c = city, n = name))

#% formatting:
print("Name: %s, Age: %d, City: %s" % (name, age, city)) 