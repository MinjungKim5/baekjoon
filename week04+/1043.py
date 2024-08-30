# https://www.acmicpc.net/problem/1043
# 거짓말

people, party_num = map(int,input().split())
beholder_input = list(map(int, input().split()))
if beholder_input[0] == 0: print(party_num); exit()
beholder_input.pop(0)
beholder = [False for _ in range(people+1)]
for b in beholder_input: beholder[b] = True

parties = []
for _ in range(party_num):
    p = list(map(int, input().split()))
    p.pop(0)
    parties.append(p)
safe = [True for _ in range(party_num+1)]
safe[0] = False
changed = True
while changed:
    changed = False
    for party in range(1, party_num+1):
        if not safe[party]: continue
        for participants in parties[party-1]:
            if beholder[participants]:
                for i in parties[party-1]: beholder[i] = True
                safe[party] = False
                changed = True
                break
count = 0
for s in safe:
    if s: count+=1
print(count)