n_of_tri = int(input())
if n_of_tri == 1: print(input()); exit()
res = [0 for _ in range(n_of_tri)]
for n in range(n_of_tri):
    arr = list(map(int, input().split(" ")))
    newres = [0 for _ in range(n_of_tri)]
    for i in range(n+1):
        if i == 0: newres[i] = res[i] + arr[i]
        elif res[i] > res[i-1]: newres[i] = res[i] + arr[i]
        else: newres[i] = res[i-1] + arr[i]
    for i in range(n+1):
        res[i] = newres[i]

max = 0
for i in range(n_of_tri):
    if res[i] > max: max = res[i]
print(max)