## https://www.acmicpc.net/problem/1991
## 트리 순회

# 문제
# 이진 트리를 입력받아 전위 순회(preorder traversal), 중위 순회(inorder traversal), 후위 순회(postorder traversal)한 결과를
# 출력하는 프로그램을 작성하시오.
# 예를 들어 위와 같은 [A -> B -> C] [B -> D] [C -> E -> F] [F -> G] 이진 트리가 입력되면,
# 전위 순회한 결과 : ABDCEFG // (루트) (왼쪽 자식) (오른쪽 자식)
# 중위 순회한 결과 : DBAECFG // (왼쪽 자식) (루트) (오른쪽 자식)
# 후위 순회한 결과 : DBEGFCA // (왼쪽 자식) (오른쪽 자식) (루트) 가 된다.

# 입력
# 첫째 줄에는 이진 트리의 노드의 개수 N(1 ≤ N ≤ 26)이 주어진다.
# 둘째 줄부터 N개의 줄에 걸쳐 각 노드와 그의 왼쪽 자식 노드, 오른쪽 자식 노드가 주어진다.
# 노드의 이름은 A부터 차례대로 알파벳 대문자로 매겨지며, 항상 A가 루트 노드가 된다.
# 자식 노드가 없는 경우에는 .으로 표현한다.

# 출력
# 첫째 줄에 전위 순회, 둘째 줄에 중위 순회, 셋째 줄에 후위 순회한 결과를 출력한다. 각 줄에 N개의 알파벳을 공백 없이 출력하면 된다.

# 예제 입력 1 
# 7
# A B C
# B D .
# C E F
# E . .
# F . G
# D . .
# G . .

# 예제 출력 1 
# ABDCEFG
# DBAECFG
# DBEGFCA

nodes = int(input())

# tree = [[0, 1, 2], [1, 3, -1], [2, 4, 5], [3, -1, -1], [4, -1, -1], [5, -1, 6], [6, -1, -1], [-1, -1, -1]]

tree = []
for _ in range(nodes + 1):
    tree.append([-1, -1, -1])

for i in range(nodes):
    list = input().split(" ")
    adjlist = [-1, -1, -1]
    for j in range(3):
        if list[j] == "." : continue
        else: adjlist[j] = ord(list[j]) - 65
    # print(adjlist)
    tree[adjlist[0]] = (adjlist)
# print(tree)

def travel(adjlist):
    global tree, preorder, inorder, postorder
    if adjlist[0] == -1: return
    char = chr(adjlist[0] + 65)
    preorder.append(char)
    left_child = adjlist[1]
    right_child = adjlist[2]
    travel(tree[left_child])
    inorder.append(char)
    travel(tree[right_child])
    postorder.append(char)
    return

preorder = []
inorder = []
postorder = []

travel(tree[0])
print("".join(preorder))
print("".join(inorder))
print("".join(postorder))