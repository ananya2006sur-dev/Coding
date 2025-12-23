num = int(input("Enter the number of students in your class: "))
if num < 0:
    print("Invalid Input")
else:
    students = []
    rollnos = []
    i = 1
    while i <= num:
        rollno = int(input("Enter the roll number of student: "))
        name = str(input("Enter the name of student: "))
        rollnos.append(rollno)
        students.append(name)
        i = i + 1 
    print("Roll No.\tName")
    j = 1
    while j <= num:
        print(rollnos[j - 1],"\t",students[j - 1])  
        j = j + 1




        