import sys
if __name__ == "__main__":
    line = sys.stdin.readline().strip()
    values = list(map(int, line.split()))
    b=reversed(values)
    for i in b:
        print(i,end=" ")