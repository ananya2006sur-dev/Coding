film_database = {}

film1 = {'Producer': 'Gauri Khan', 'Director': 'Farah Khan', 'Year of Release': 2007, 'Success': 'Super-Hit'}
film2 = {'Producer': 'Dhilin Mehta', 'Director': 'Imtiaz Ali', 'Year of Release': 2007, 'Success': 'Hit'}
film3 = {'Producer': 'Vidhu Vinod Chopra', 'Director': 'Rajkumar Hirani', 'Year of Release': 2009, 'Success': 'Blockbuster'}
film4 = {'Producer': 'Aditya Chopra', 'Director': 'Yash Chopra', 'Year of Release': 2012, 'Success': 'Hit'}
film5 = {'Producer': 'Mukesh Bhatt', 'Director': 'Mohit Suri', 'Year of Release': 2013, 'Success': 'Blockbuster'}

film_database.update({"Om Shanti Om": film1})
film_database.update({"Jab We Met": film2})
film_database.update({"3 Idiots": film3})
film_database.update({"Jab Tak Hai Jaan": film4})
film_database.update({"Aashiqui 2": film5})

choice1 = int(input("Enter the no. of films whose details you want: "))

if choice1 == 0:
    print("Thank You for your response!")
elif choice1 <= 5:
    i = choice1
    while i > 0:
        name1 = str(input("Enter the name of the film whose details you want: "))
        if name1 in film_database:
            print("Film Name Found")
            print("Film Name: ", name1)
            print("Film Producer: ", film_database[name1]['Producer'])
            print("Film Director: ", film_database[name1]['Director'])
            print("Film Year of Release: ", film_database[name1]['Year of Release'])
            print("Film Success: ", film_database[name1]['Success'])
            print("**********")
            i -= 1
        else:
            print("Film Name Not Found")
            i -= 1
else:
    print("There are not enough no. of films in the database")

choice2 = int(input("Enter the no. of films which you want to remove: "))

if choice2 == 0:
    print("Thank You for your response!")
elif choice2 <= 5:
    i = choice2
    while i > 0:
        name2 = str(input("Enter the name of the film which you want to remove: "))
        if name2 in film_database:
            film_database.pop(name2)
            print("Film removed")
            i -= 1
        else:
            print("Film Name Not Found")
            i -= 1
else:
    print("There are not enough no. of films in the database")