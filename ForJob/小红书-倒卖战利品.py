# #问题描述，商贩看见好的商品之后，再看不上比它差的宝物了，如何组织顺序
#倒卖战利品
def takeSecond(elem):
    return elem[2]

def tackle(candys):
    count=0
    temp=-1
    for i in range(len(candys)):
        scores=candys[i][0]+candys[i][1]
        candys[i].append(scores)
    candys.sort(key=takeSecond)
    for candy in candys:
        if(candy[2]!=temp):
            count+=1
            temp=candy[2]
    return count

import sys
if __name__ == "__main__":
    n = int(sys.stdin.readline().strip())
    candys=[]
    for i in range(n):
        candy=[]
        line = sys.stdin.readline().strip()
        values = list(map(int, line.split()))
        candy.append(values[0])
        candy.append(values[1])
        candys.append(candy)
    # candys=[[3,2],[1,1],[1,3],[2,2]]
    res=tackle(candys)
    print(res)