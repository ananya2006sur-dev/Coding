districts = []
Maharashtra = ["Pune", "Aurangabad", "Satara", "Solapur", "Sangli"]
Gujarat = ["Ahmedabad", "Surat", "Vadodara", "Rajkot", "Bhavnagar"]
Kerala = ["Kochi", "Kozhikode", "Thiruvananthapuram", "Thrissur", "Kollam"]
i = 0 
while i < len(Maharashtra):
    districts.insert(i, Maharashtra[i])
    i = i + 1
j = 0
while j < len(Gujarat):
    districts.append(Gujarat[j])
    j = j + 1

districts.extend(Kerala)

print("Districts in Maharashtra, Gujarat and Kerala are: ")
for k in districts:
    print(k)

dist1 = str(input("Enter the district name you want to search for in the list of distrcits: "))
if dist1 in districts:
    print("District found")
else:
    print("District not found")

dist2 = str(input("Enter the district name you want to remove in the list of districts: "))
if dist2 in districts:
    districts.remove(dist2)
    print("District removed")
    print("Updated list of districts is: ")
    for l in districts:
        print(l)
else:
    print("District not found, can't remove")

print("The first five districts are: ", districts[:5])
