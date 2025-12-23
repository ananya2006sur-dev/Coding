import math as m 

n = int(input("Enter the number of cricket grounds: "))
ground_names = []
ground_radii = [] 
for i in range(n):
    name = str(input("Enter the name of the ground: "))
    radius = float(input("Enter the radius of the ground in metres: "))
    ground_names.append(name)
    ground_radii.append(radius)
    print("Ground accepted")
    print("+++++++++++++++")
ground_areas = [] 
for i in range(n):
    area = m.pi * ground_radii[i] ** 2
    ground_areas.append(area) 
    print("+++++++++++++++")
for i in range(n):
    print("Ground name: ", ground_names[i])
    print("Ground radius in metres: ", ground_radii[i])
    print("Ground area is square metres: ", ground_areas[i])
    print("**********")


    