myList = []

for i in range(5):
    val = input("Enter a value : ")
    n = int(val)
    myList.append(n)

sum = 0
for n in myList:
    sum = sum+n

print(" The sum of given values is : ", sum)
