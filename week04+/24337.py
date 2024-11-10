# https://www.acmicpc.net/problem/24337
# 가희와 탑

n,a,b = map(int,input().split())
if n+1 < a+b: print(-1); exit()
buildings = [1 for _ in range(n)]
# a가 1일때, b가 1일떄, 아니면 둘다 2 이상일때에 따라 다름
if a == 1:
    buildings[0] = b
    for i in range(1,b):
        buildings[-i] = i
elif b == 1:
    for i in range(1,a):
        buildings[-i] = a+1-i
elif a > b:
    for i in range(1,a+b):
        if i < b:
            buildings[-i] = i
        else:
            buildings[-i] = a+b-i
elif a <= b:
    for i in range(1,a+b):
        if i <= b:
            buildings[-i] = i
        else:
            buildings[-i] = a+b-i

for i in buildings:
    print(i,end=" ")