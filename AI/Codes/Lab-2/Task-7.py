def isP(word):
    word = input("Enter a Word : ")
    temp = word[::-1]
    if temp.capitalize() == word.capitalize():
        return True
    else:
        return False


print(isP("dead"))
