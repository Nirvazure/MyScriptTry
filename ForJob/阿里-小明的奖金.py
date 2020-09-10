# 我觉得可能就是简单的遍历列表的问题，有点可惜

# 每次获奖后，这个程序首先会随机产生若干0~1之间的实数{p_1, p_2, …, p_n}，
# 然后从小明开始，第一轮以p_1的概率将奖金全部分配给小明，
# 第二轮以p_2的概率将奖金全部分配给小华，这样交替地小明、
# 小华以p_i的概率获得奖金的全部，
# 一旦奖金被分配，则程序终止
# ，如果n轮之后奖金依旧没发出，
# 则从p_1开始继续重复（这里需要注意，如果n是奇数，则第二次从p_1开始的时候，这一轮是以p_1的概率分配给小华）；
# 直到100轮，如果奖金还未被分配，程序终止，两人约定通过支付宝将奖金捐出去。

# 输入:
# 输入数据包含N+1行，
# 第一行包含一个整数N
# 接下来N行，每行一个0~1之间的实数，从p_1到p_N
# 输出:
# 单独一行，输出一个小数，表示小明最终获得奖金的概率，结果四舍五入，小数点后严格保留4位(这里需要注意，如果结果为0.5，则输出0.5000)。
# 输入范例:
# 1
# 0.999999
# 输出范例:
# 1.0000

import sys

class Solution:

    def tackle(self,p_list):
        xiaoming=0
        tmp=0
        for i in range(0,len(p_list),2):
            print(p_list[i])
            tmp=1-p_list[i]
            tmp
            xiaoming+=p_list[i]
        return xiaoming

    def tset(self,Ps,index):
        int(index)
        print(Ps,index)
        for i in range(index-1,0):
            print(i)
            print(Ps[i])
            res=Ps[index]*(1-Ps[i])
            print(res)


s=Solution()

p_list=[0.2,0.6,0.3,0.5,0.7,0.8]
s.tset(p_list,5)
# xiaoming=s.tackle(p_list)
# print(xiaoming)

# flag=True
# while(flag == True):
#     m=int(sys.stdin.readline().strip('\n'))
#     n=int(sys.stdin.readline().strip('\n'))
#     k=int(sys.stdin.readline().strip('\n'))
#     if(1<=m<=50 and 1<=n<=50 and 1<=k<=50):
#         flag=False
#         result=s.tackle(m,n,k)
#         print(result)
#     else:
#         flag=True
#         print('re input')
