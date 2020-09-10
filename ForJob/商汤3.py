import sys


def convert(n, i):
    ans = []
    while n/i > 0:
        ans.append(str(n % i))
        n = n//i
    ans.reverse()
    return ''.join(ans)


def tackle(n, x):
    i = n
    while(int(convert(n, i)) < x):
        i -= 1
    return i


if __name__ == "__main__":
    # line = sys.stdin.readline().strip()
    # values = list(map(int, line.split()))
    # ans = tackle(values[0], values[1])
    ans = tackle(19, 13)
    print(ans)
