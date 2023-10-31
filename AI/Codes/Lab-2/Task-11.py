sample = {("shoaib", "ali"): "03480058526",
          ("aib", "li"): "03319051913",
          ("sib", "ai"): "03119550093", }

firstName = input("Enter first name: ")
lastname = input("Enter last name: ")

searchTuple = (firstName, lastname)

if searchTuple in sample:
    print(sample[searchTuple])
else:
    print("name not found")
