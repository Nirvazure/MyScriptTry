import sys

class Solution:

    def tackle(self,n,nums):
        count=0
        for i in range(len(nums)):
            count+=doIt(nums,i)
        return count%998244353

        def doIt(self,items,i):
            count=0
            if(i==1):
                if(items[i]==0):
                    count=998244352
                else:
                    count=items[i]
            elif(i==2 and i==len(items)):
                count+=doIt(items,i)-doIt(items,i-1)
            else:
                count+=max(doIt(items,i+1),doIt(items,i-1))-doIt(items,i)
            return count

s=Solution()

n = [int(temp) for temp in input().split()]
n=n[0]
nums = [int(temp) for temp in input().split()]
nums=nums[:n]
for i in range(len(nums)):
    if(nums[i]>200):
        print('输入不正确')
    else:
        result=s.tackle(n,nums)
        print(result)

# 样例输入
# 3
# 2 0 1
# 样例输出
# 1

# 时间限制：C/C++语言 1000MS；其他语言 3000MS
# 内存限制：C/C++语言 65536KB；其他语言 589824KB
# 题目描述：
# 有一个含有n个数字的序列，每个数字的大小是不超过200的正整数，同时这个序列满足以下条件：

# 1.    a_1<=a_2

# 2.    a_n<=a_(n-1) （此时n>2）

# 3.    a_i<=max(a_{i-1},a_{i+1})

# 但是很不幸的是，在序列保存的过程中，有些数字丢失了，请你根据上述条件，计算可能有多少种不同的序列可以满足以上条件。

# 输入
# 输入第一行是一个n，表示这个序列的长度。(3<=n<=10^4)

# 输入第二行有n个非负整数，中间用空格隔开，如果数字为0，说明这个数字丢失了，其他数字则都在1-200之间。

# 输出
# 输出仅包含一个整数，即方案数对998244353取模的结果。


# 样例输入
# 3
# 2 0 1
# 样例输出
1