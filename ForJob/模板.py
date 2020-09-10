import sys

def tackle(data)->int:
    res=data+1
    return res

if __name__ == '__main__':
    n=int(sys.stdin.readline().strip())
    ans=0
    for i in range(n):
        line=sys.stdin.readline().strip()
        values=list(map(int,line.split()))
        for v in values:
            ans+=v
    print(ans)


class Solution:
    def tackle(self):
        pass

s=Solution()
ans=s.tackle()
print(ans)

n = [int(temp) for temp in input("Please enter param").split()]

for i in tackle(values):
    print(i, end=' ')