# https://www.acmicpc.net/problem/9536
# 여우는 어떻게 울지?

# 문제
# 고대 미스테리로 전해지는 여우의 울음소리를 밝혀내기 위해 한신이는 고성능 녹음기로 무장하고 숲으로 들어갔다.
# 하지만 숲에는 동물들이 가득해, 녹음된 음성에는 다른 동물들의 울음소리가 섞여 있다.
# 그러나 한신이는 철저한 준비를 해 왔기 때문에 다른 동물들이 어떤 울음소리를 내는지 정확히 알고 있다.
# 그러므로 그 소리를 모두 걸러내면 남은 잡음은 분명히 여우의 울음소리일 것이다.

# 입력
# 첫 번째 줄에는 테스트케이스의 개수 T가 입력된다. 각 테스트케이스는 아래와 같이 구성되어 있다.
# 테스트케이스의 첫 줄에는 몇 개의 단어로 이루어진 녹음된 소리가 입력된다. 단어는 알파벳 소문자로만 이루어져 있으며 공백으로 구분된다.
# 단어의 길이는 최대 100글자이고, 단어의 개수는 최대 100개이다.
# 다음 줄부터는 여우를 제외한 동물들의 울음소리가 <동물> goes <소리>의 형태로 입력된다.
# 최소 1마리, 최대 100마리이며, 이름은 최대 100글자이고 실제로 존재하는 동물의 이름이다.
# 여우를 제외한 동물의 울음소리는 한 단어이고 최대 100글자이다.
# 마지막 줄에는 한신이가 알고 싶어하는 질문이 주어진다. what does the fox say?

# 출력
# 각 테스트케이스마다 여우의 울음소리를 한 줄씩, 녹음된 순서대로 출력한다. 여우의 울음소리가 녹음되어 있음이 보장된다. (알려진 것과는 달리, 여우는 모스 부호로 의사소통하지 않는다.)

# 예제 입력 1 
# 1
# toot woof wa ow ow ow pa blub blub pa toot pa blub pa pa ow pow toot
# dog goes woof
# fish goes blub
# elephant goes toot
# seal goes ow
# what does the fox say?
# 예제 출력 1 
# wa pa pa pa pa pa pow
import sys
testcase = int(sys.stdin.readline())
for _ in range(testcase):
    rec = sys.stdin.readline().strip().split(" ")

    # 입력
    howl = []
    while(True):
        input = sys.stdin.readline().strip()
        if input.find('what does the fox say?') != -1: break
        howl.append(input.split(" ")[2])
    
    # 출력
    filtered = ""
    for voice in rec:
        if howl.count(voice) == 0: filtered += (voice + " ")
    
    print(filtered)