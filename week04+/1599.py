# https://www.acmicpc.net/problem/1599
# 민식어

# 문제
# 무엇인가를 창조하는 것은 어렵다. 오민식은 지금까지 어려운 다른나라의 언어를 쓰면서 백성들이 고통에 받는 것을 슬퍼하고 새로운 언어를 만들고자 했다.
# 그는 창조의 고통에 시달리던 중에 결국 오영식에게 자신의 못다 이룬 꿈을 꼭 이루어달라면서 오영식에게 창조의 임무를 넘겼다.
# 오영식은 자신의 형이 창조에 고통에 시달리는 모습을 보고 마음이 아파서 자신은 창조를 하지 않기로 했다.
# 영식이는 표절을 하기로 했는데 세계적인 추세에 맞게 영어를 표절하기로 했다. 영식이는 자신의 형의 이름을 따서 민식어라고 이름붙였다.

# 민식어에는 알파벳이 20개가 있다.
# 영어는 a b c d e f g h i j k l m n o p q r s t u v w x y z의 순서이지만, 민식어는 a b k d e g h i l m n ng o p r s t u w y의 순서이다.
# 민식어는 영어의 순서를 따르기는 하지만, 약간 변형시켜서 따른다. 그리고 ng는 n과 o사이에 오는 하나의 알파벳이다. ng는 무조건 이 알파벳으로 생각한다.
# 영식이는 사람들이 쉽게 민식어를 배울 수 있도록 민식어 사전을 만들려고 한다. 따라서 몇 개의 단어를 정렬하고자 한다.
# 민식어 단어가 주어졌을 때, 그것을 민식어의 순서대로 정렬하는 프로그램을 작성하시오.

# 입력
# 첫째 줄에 민식어 단어의 개수 N이 주어진다. N은 50보다 작거나 같은 자연수이다. 둘째 줄부터 한 줄에 하나씩 단어가 입력으로 들어온다.
# 단어의 길이는 최대 50자이다. 민식어에 없는 알파벳이 입력으로 주어지는 경우는 없다. 모든 단어는 중복되지 않는다.

# 출력
# 첫째 줄부터 차례대로 정렬한 결과를 출력한다.

# 예제 입력 1 
# 4
# abakada
# alpabet
# tagalog
# ako
# 예제 출력 1 
# abakada
# ako
# alpabet
# tagalog

n_of_words = int(input())
words = []
alphabet = {"a":1, "b":2, "k":3, "d":4, "e":5, "g":6, "h":7, "i":8, "l":9, "m":10, "n":11, "o":13, "p":14, "r":15, "s":16, "t":17, "u":18, "w":19, "y":20}
for n in range(n_of_words):
    str = input()
    word = list(str)
    enumed = 0
    seat = 21**50
    is_n = False
    for l in range(len(word)):
        if word[l] == "g" and is_n:
            enumed += seat*21
            is_n = False
            continue

        enumed += seat*alphabet[word[l]]
        seat = seat/21
        if word[l] == "n": is_n = True
        else: is_n = False
    
    words.append([enumed, str])

words = sorted(words)

for i in range(n_of_words):
    print(words[i][1])