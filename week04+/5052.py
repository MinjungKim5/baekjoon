# https://www.acmicpc.net/problem/5052
# 전화번호 목록

# 문제
# 전화번호 목록이 주어진다. 이때, 이 목록이 일관성이 있는지 없는지를 구하는 프로그램을 작성하시오.
# 전화번호 목록이 일관성을 유지하려면, 한 번호가 다른 번호의 접두어인 경우가 없어야 한다.
# 예를 들어, 전화번호 목록이 아래와 같은 경우를 생각해보자
# 긴급전화: 911
# 상근: 97 625 999
# 선영: 91 12 54 26
# 이 경우에 선영이에게 전화를 걸 수 있는 방법이 없다.
# 전화기를 들고 선영이 번호의 처음 세 자리를 누르는 순간 바로 긴급전화가 걸리기 때문이다.
# 따라서, 이 목록은 일관성이 없는 목록이다.

# 입력
# 첫째 줄에 테스트 케이스의 개수 t가 주어진다. (1 ≤ t ≤ 50)
# 각 테스트 케이스의 첫째 줄에는 전화번호의 수 n이 주어진다. (1 ≤ n ≤ 10000)
# 다음 n개의 줄에는 목록에 포함되어 있는 전화번호가 하나씩 주어진다.
# 전화번호의 길이는 길어야 10자리이며, 목록에 있는 두 전화번호가 같은 경우는 없다.

# 출력
# 각 테스트 케이스에 대해서, 일관성 있는 목록인 경우에는 YES, 아닌 경우에는 NO를 출력한다.

# 예제 입력 1 
# 2
# 3
# 911
# 97625999
# 91125426
# 5
# 113
# 12340
# 123440
# 12345
# 98346
# 예제 출력 1 
# NO
# YES
import sys
input = sys.stdin.readline

class TrieNode:
    def __init__(self):
        self.children = {}
        self.isEnd = False

class Trie:
    def __init__(self):
        self.root = TrieNode()
    
    def insert(self, str):
        node = self.root # 루트부터 실행
        for char in str:
            if char not in node.children: # 이 글자가 없으면 등록
                node.children[char] = TrieNode()
            node = node.children[char] # 다음 글자 위치로 이동
            if node.isEnd: # 이미 여기서 끝난 스트링이 있으면 그게 접두사
                return False
        node.isEnd = True
        if node.children: # 내가 다 끝났는데 그 뒤에도 있으면 내가 접두사
            return False
        return True
    
for _ in range(int(input())):
    trie = Trie()
    phonenumbers = []
    for _ in range(int(input())):
        phonenumbers.append(input().strip())
    yes = True
    for num in phonenumbers:
        if not trie.insert(num):
            yes = False
            break
    print("YES" if yes else "NO")