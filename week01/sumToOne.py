while True:
    n = int(input())
    def ssum(n):
        if n > 0:
            return (n**2 + n)/2
        else:
            return (-n**2 + n + 2)/2
    print(ssum(n))