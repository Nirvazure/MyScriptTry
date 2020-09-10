# 班上同学聚餐吃火锅，一锅煮了的M(1<=M<=50)个鱼丸和N(1<=N<=50)个肉丸，
# 现欲将M个鱼丸和N个肉丸分到K(1<=K<=50)个碗中，
# 允许有空碗，鱼丸和肉丸不允许混在同一个碗里，问共有多少种装法？
# 假设碗足够大，能装50个鱼丸或者50个肉丸，碗之间也没有区别，
# 因此当M=N=1，K=3时，只有1种装法，因为(1,1,0)(1,0,1)(0,1,1)被看作是同一种装法。

import syss

class Solution:

    def tackle(self,m,n,k):
        result=m+n+k
        result=result%10000
        return result

s=Solution()

for line in sys.stdin:
    a = line.split()

while(flag == True):
    m=int(sys.stdin.readline().strip('\n'))
    n=int(sys.stdin.readline().strip('\n'))
    k=int(sys.stdin.readline().strip('\n'))
    if(1<=m<=50 and 1<=n<=50 and 1<=k<=50):
        flag=False
        result=s.tackle(m,n,k)
        print(result)
    else:
        flag=True
        print('re input')
