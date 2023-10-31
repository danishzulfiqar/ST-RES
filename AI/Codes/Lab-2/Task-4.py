myList1 = []

print("Enter Objects of 1st List : ")

for i in range(5):
    val = input("Enter Value : ")
    n = int(val)
    myList1.append(n)

myList2 = []

print("Enter Objects of 2nd List : ")

for i in range(5):
    val = input("Enter Value : ")
    n = int(val)
    myList2.append(n)

list3 = myList2+myList1

print(list3)
