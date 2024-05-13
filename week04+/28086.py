import re


def octal(dec):
    oct = 0
    digit = 1
    while(dec):
        oct += (dec%10)*digit
        dec = dec//10
        digit = digit*8
    return oct

def decimal(oct):
    dec = 0
    digit = 1
    while(oct):
        dec += (oct%8)*digit
        oct = oct//8
        digit = digit*10
    return dec

inputstr = input()
pattern = r'(-?\+d)([-+*/])(-?+d)'

# match = re.match(pattern, inputstr)
# a = int(match.group(1))
# oper = match.group(2)
# b = int(match.group(3))

a, oper, b = re.split(pattern, inputstr)

a = octal(a)
b = octal(b)
c = 0
if oper == '+': c = a + b
elif oper == '-': c = a - b
elif oper == '*': c = a * b
else:
    if b == 0:
        print("invalid")
        exit()
    elif a*b < 0:
        if (a%b) == 0: c = a // b
        else: c = a//b - 1
    else: c = a//b

if c < 0:
    c = -c
    print("-{}".format(decimal(c)))
else: print("{}".format(decimal(c)))