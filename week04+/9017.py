# https://www.acmicpc.net/problem/9017
# 크로스 컨트리

# 문제
# 크로스 컨트리 달리기는 주자들이 자연적인 야외의 지형에 만들어진 코스를 달리는 운동 경기이다.
# 경주 코스는 일반적으로 4에서 12 킬로미터이며, 숲이나 넓은 땅을 통과하는 풀과 흙으로 된 지면과 언덕과 평평한 지형을 포함한다.
# 이 경기는 주자들의 개인성적을 매기고, 이를 가지고 팀의 점수를 계산한다. 
# 한 팀은 여섯 명의 선수로 구성되며, 팀 점수는 상위 네 명의 주자의 점수를 합하여 계산한다.
# 점수는 자격을 갖춘 팀의 주자들에게만 주어지며, 결승점을 통과한 순서대로 점수를 받는다. 이 점수를 더하여 가장 낮은 점수를 얻는 팀이 우승을 하게 된다.
# 여섯 명의 주자가 참가하지 못한 팀은 점수 계산에서 제외된다. 동점의 경우에는 다섯 번째 주자가 가장 빨리 들어온 팀이 우승하게 된다.

# 예를 들어, 다음의 표를 살펴보자.
# 등수	1	2	3	4	5	6	7	8	9	10	11	12	13	14	15
# 팀	A	B	C	C	A	C	B	D	A	A	C	A	C	C	A
# 점수	1	n/a	2	3	4	5	n/a	n/a	6	7	8	9	10	11	12
# 팀 B 와 D 는 선수의 수가 여섯이 아니므로, 점수를 받을 수 없다. 팀 A 의 점수는 18 (1+4+6+7)이고, 팀 C 의 점수는 18 (2+3+5+8)이다.
# 이 경우 두 팀의 점수가 같으므로 다섯 번째로 결승점을 통과한 선수를 고려한다.
# A 팀의 다섯 번째 선수의 점수가 C 팀의 다섯 번째 선수의 점수보다 적으므로 A 팀이 우승팀이 된다.
# 모든 선수들의 등수가 주어질 때, 우승팀을 구하는 프로그램을 작성하라. 각 팀의 참가 선수가 여섯보다 작으면 그 팀은 점수 계산에서 제외됨을 주의하라.
# 여섯 명 보다 많은 선수가 참가하는 팀은 없고, 적어도 한 팀은 참가 선수가 여섯이며, 모든 선수는 끝까지 완주를 한다고 가정한다.

# 입력
# 입력 데이터는 표준입력을 사용한다. 입력은 T 개의 테스트 케이스로 주어진다. 입력 파일의 첫 번째 줄에 테스트 케이스의 수를 나타내는 정수 T 가 주어진다.
# 두 번째 줄부터는 두 줄에 하나의 테스트 케이스에 해당하는 데이터가 주어진다. 각 테스트 케이스의 첫 번째 줄에는 하나의 정수 N (6 ≤ N ≤ 1,000)이 주어진다.
# 두 번째 줄에는 팀 번호를 나타내는 N 개의 정수 t1, t2, …, tN 이 공백을 사이에 두고 주어진다. 각 팀은 1 과 M(1 ≤ M ≤ 200)사이의 정수로 표현된다.

# 출력
# 출력은 표준출력을 사용한다. 하나의 테스트 케이스에 대한 우승팀의 번호를 한 줄에 출력한다. 

# 예제 입력 1 
# 2
# 15
# 1 2 3 3 1 3 2 4 1 1 3 1 3 3 1
# 18
# 1 2 3 1 2 3 1 2 3 3 3 3 2 2 2 1 1 1
# 예제 출력 1 
# 1
# 3

from sys import stdin

testcases = int(stdin.readline())
for _ in range(testcases):
    n = int(stdin.readline())
    seq = list(map(int, stdin.readline().strip().split(" ")))
    teams = [0 for _ in range(201)]
    for i in seq: teams[i] +=1
    for i in range(201):
        if teams[i] == 6: teams[i] = True
        else: teams[i] = False
    scores = [[0,0,0] for _ in range(201)] # [몇명, 총합 몇등, 5등은 몇등]
    score = 1
    for i in range(n):
        if not teams[seq[i]]: continue
        scores[seq[i]][0] += 1
        if scores[seq[i]][0] < 5: scores[seq[i]][1] += score
        if scores[seq[i]][0] == 5: scores[seq[i]][2] = score
        score += 1

    # winner[0] 팀이 총합 [1]등으로, 5등은 [2]등으로 우승
    winner = [0, 2000000000, 2000000000]
    for i in range(1, 201):
        if scores[i][0] != 6: continue
        if scores[i][1] < winner[1] or (scores[i][1] == winner[1] and scores[i][2] < winner[2]):
            winner[0] = i
            winner[1] = scores[i][1]
            winner[2] = scores[i][2]

    print(winner[0])