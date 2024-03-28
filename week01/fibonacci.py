def fib(n):
    arr = [1]
    a = 0
    b = 1
    temp = 0
    if n == 1:
        return arr
    for _ in range(n-1):
        temp = b
        b += a
        a = temp
        arr.append(b)
    return arr
    
print(fib(int(input())))