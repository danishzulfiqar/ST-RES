myList = []

print("Enter object of First List : ")

for i in range(5):
    val = input("Enter Value : ")
    n = int(val)
    myList.append(n)

s = input("Enter a Value to find in the list : ")
print(myList)
n = int(s)

found = n in myList
if found == True:
    print("Found!")
else:
    print("Not found!")
