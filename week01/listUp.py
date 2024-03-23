n = int(input('자료수를 입력하세요.: '))
inputList = []

for i in range(n):
    value = int(input(f'{i+1} 번째 값을 입력하세요.: '))
    inputList.append(value)

listUpList = []

def listUp(a, n):
    global listUpList
    if n == 0:
        listUpList.append(a[n])
        return
    listUp(a, n-1)
    if len(a) == len(listUpList):
        return listUpList
    for i in range(len(listUpList)):
        if a[n] >= listUpList[i]:
            listUpList.insert(i,a[n])
            return
    listUpList.append(a[n])


listUp(inputList, n)
print(listUpList)