"""
变量描述：
*. N -- 用户输入的商品面额（需要进行可行性检查）
*. coins数组，由小到大排列方便迭代（因为实际情况是先检查最大的面额匹配数目）
*. total用来存放最终结果
算法描述：
简单的迭代思想
1. 先计算出需要找零的钱数
2. 由于要算出最少找零数目，由小到大迭代coins
    2-1.如果找零数大于当前coin，算出该面值硬币数目加入total
    2-2.如果小于当前coin，继续循环直至退出循环
"""

coins=[64,16,4,1]

def getCharge(N):
    total=0
    charge=1024-N
    for i in coins:
        if(charge>=i):
            num=charge%i
            charge-=num*i
            print(i,"---",num)
            total+=num
        else:
            continue
    return total

if __name__ == '__main__':
    #N=input()
    total=getCharge(200)
    print(total)