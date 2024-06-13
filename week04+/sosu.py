sosu = [2]
for i in range(3, 3163):
    na = True
    for s in sosu:
       if s*s > i: break
       if i%s == 0:
            na = False
            break
    if na == True:
        sosu.append(i)
        print(i, end=", ")