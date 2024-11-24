# https://www.acmicpc.net/problem/14658
# 하늘에서 별똥별이 빗발친다

# 문제
# 지구의 파괴를 막기 위해서는 지표면에 떨어지는 별똥별의 수를 최소화해야 한다. 욱제는 커다란 네모난 L*L 크기의 트램펄린을 준비했다.
# 별똥별이 어디로 떨어질지는 이미 알고 있기 때문에, 욱제는 이 트램펄린으로 최대한 많은 별똥별을 우주로 튕겨낼 계획이다.
# 하지만 학교 예산으로 트램펄린을 구매하는 욱제는 이 긴급한 와중에도 예산 심의 통과를 기다리느라 바쁘다!
# 욱제를 도와 세계를 구하자. 최대한 많은 별똥별을 튕겨내도록 트램펄린을 배치했을 때, 지구에는 몇 개의 별똥별이 부딪히게 될까?
# (별똥별이 떨어지는 위치는 겹치지 않으며 별똥별은 트램펄린의 모서리에 부딪혀도 튕겨나간다!) 트램펄린은 비스듬하게 배치 할 수 없다.

# 입력
# 첫째 줄에 네 정수 N, M, L, K가 주어진다. (1 ≤ N, M ≤ 500,000, 1 ≤ L ≤ 100,000, 1 ≤ K ≤ 100)
# N은 별똥별이 떨어지는 구역의 가로길이, M은 세로길이, L은 트램펄린의 한 변의 길이, K는 별똥별의 수를 뜻한다.
# 이후 K개의 줄에 걸쳐 별똥별이 떨어지는 위치의 좌표 (x, y)가 주어진다. (0 ≤ x ≤ N, 0 ≤ y ≤ M)

# 출력
# 욱제가 트램펄린으로 최대한 많은 별똥별을 튕겨낼 때, 지구에 부딪히는 별똥별의 개수를 출력한다.

# 예제 입력 1 
# 12 10 4 7
# 2 4
# 7 3
# 3 1
# 5 6
# 4 7
# 12 10
# 8 6
# 예제 출력 1 
# 3

n,m,l,k = map(int, input().split())
meteors = []
xs = []
ys = []
for _ in range(k):
    meteor = (tuple(map(int,input().strip().split())))
    meteors.append(meteor)
    ys.append(meteor[0])
    xs.append(meteor[1])
maxNum = 0
for y in ys:
    for x in xs:
        count = 0
        for meteor in meteors:
            if (y<=meteor[0]<=y+l) and (x<=meteor[1]<=x+l):
                count += 1
        if count > maxNum: maxNum = count

print(k-maxNum)