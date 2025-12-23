players = () 
players_list = list(players)
n = int(input("Enter the number of players: "))
for i in range(0, n):
    player = str(input("Enter the name of the player: "))
    players_list.append(player)
    print("Player accepted")
    print("+++++++++++++++")
players = tuple(players_list)

print("The players are: ", players)

choice = input("Do you want to swap any two players' positions? Kindly answer 'yes' or 'no': ")
if choice == 'yes':
    name1 = input("Enter the first player whose position you want to swap with that of other: ")
    name2 = input("Enter the second player whose position you want to swap with that of previous one: ")
    if name1 in players_list and name2 in players_list:
        l = players_list.index(name2)
        players_list[players_list.index(name1)] = name2
        players_list[l] = name1
    else:
        print("Couldn't find either or both of the players")
elif choice == 'no':
    print("Thank You for your response! /n Have a good day!")
else:
    print("Kindly say 'yes' or 'no'")
    
players = tuple(players_list)
print("The players are: ", players)

