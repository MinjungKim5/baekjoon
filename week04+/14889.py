# https://www.acmicpc.net/problem/14889
# 스타트와 링크

n_of_members = int(input())
matrix = []
for n in range(n_of_members):
    row = list(map(int,input().strip().split(" ")))
    matrix.append(row)
min = 1000000
strip = [0 for _ in range(n_of_members)]
def combi(count, last_selected):
    global strip
    global min
    if n_of_members//2-count >= n_of_members-last_selected: return
    if count == n_of_members//2:
        start_stat, link_stat = 0,0
        rev_strip = [0 for _ in range(n_of_members)]
        q = []
        revq = []
        for i in range(n_of_members):
            rev_strip[i] = 1-strip[i]
            if strip[i]: q.append(i)
            else: revq.append(i)
        while q:
            row = q.pop(0)
            rrow = revq.pop(0)
            for i in range(n_of_members):
                start_stat += strip[i]*matrix[row][i]
                link_stat += rev_strip[i]*matrix[rrow][i]
        if start_stat == link_stat: print(0); exit()
        if abs(start_stat-link_stat) < min: min = abs(start_stat-link_stat)
        return
    for i in range(last_selected+1,n_of_members):
        strip[i] = 1
        combi(count+1, i)
        strip[i] = 0

for n in range(0,n_of_members//2):
    strip[n] = 1
    combi(1,n)
    strip[n] = 0

print(min)
