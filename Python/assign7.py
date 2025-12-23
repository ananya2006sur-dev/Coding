#create file and add text
with open("course-outcome.txt",'w') as f :
    f.write("1.Implement program to solve real life problems\n")
    f.write("2.Implement python program using appropriate control structure,data types,operation and functions\n")
    f.write("3.Execute python programs\n")
    f.write("4.Test Python Programs for various inputs.\n")
    f.flush()

#appending more data in text file
with open("course-outcome.txt",'a') as f :
    f.write("\nPython is fun to learn")
    f.flush() 

with open("course-outcome.txt",'r') as f :
    print(f.readlines())
    print("\n")
   
with open("course-outcome.txt",'r') as f :
    for i in range(0,4) :
        print(f.readline())
    print("\n")
   
with open("course-outcome.txt",'r') as f :
    print(f.read())

    