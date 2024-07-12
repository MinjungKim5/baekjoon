# https://www.acmicpc.net/problem/23304
# 아카라카

def checkAKA(akaraka):
    if len(akaraka) == 1: print("AKARAKA"); exit()
    if (akaraka == "".join(reversed(list(akaraka)))):
        aka = akaraka[:len(akaraka)//2]
        checkAKA(aka)
    else: print("IPSELENTI"); exit()

checkAKA(input().strip())