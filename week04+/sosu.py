sosu = [2]
for i in range(3, 1000000):
    na = True
    for s in sosu:
       if s*s > i: break
       if i%s == 0:
            na = False
            break
    if na == True:
        sosu.append(i)
        print(i, end=", ")
with open('./answer.txt', 'w+') as file:
    file.write('\n'.join(map(str,sosu)))