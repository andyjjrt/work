def GCD(a, b):
    if a % b == 0:
        return b
    else:
        return GCD(b, a%b)

if __name__ == "__main__":
    n = input()
    n = int(n)
    for i in range(0,n):
        a,b = input().split()
        a = int(a)
        b = int(b)
        c = GCD(a,b)
        print(c)
