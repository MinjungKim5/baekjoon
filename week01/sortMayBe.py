numlist = [4, 2, 3, 1, 5, 3, 4]
print("origin list is: ", end="")
print(numlist)
def mySort(numlist):
    oldlist = numlist.copy()
    for i in range(len(numlist) - 1):
        print(f"i = {i}")
        if numlist[i] > numlist[i + 1]:
            bigger = numlist[i]
            numlist[i] = numlist[i + 1]
            numlist [i + 1] = bigger
            print("change!: ", end="")
            print(numlist)
        else:
            print("no change: ", end="")
            print(numlist)
    print("oldlist is ", end="")
    print(oldlist)
    print("now numlist is ", end="")
    print(numlist)
    if oldlist == numlist:
        print("----------끝----------")
        print(numlist)
        return
    print("----------다시----------")
    mySort(numlist)

mySort(numlist)