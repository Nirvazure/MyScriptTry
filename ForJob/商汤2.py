import sys

def tackle(A):
    maxRes = 0
    minRes = 0
    nowMaxSum = 0
    nowMinSum = 0
    sumNum = 0
    for i in range(len(A)):
        sumNum += A[i]
        nowMaxSum = max(A[i], nowMaxSum+A[i])
        nowMinSum = min(A[i], nowMinSum+A[i])
        maxRes = max(maxRes, nowMaxSum)
        minRes = min(minRes, nowMinSum)
    if maxRes < 0:
        return maxRes
    return max(maxRes, sumNum-minRes)


if __name__ == "__main__":
    n = sys.stdin.readline().strip()
    line = sys.stdin.readline().strip()
    values = list(map(int, line.split()))
    ans = tackle(values[0:int(n)])
    print(ans)
