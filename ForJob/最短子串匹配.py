# 给定文本text和待匹配字符串pattern，二者皆只包含小写字母，并且不为空。
# 在text中找出匹配pattern的最短字符串，匹配指按序包含pattern，但不要求pattern连续。
# 如text为abaacxbcbbbbacc，pattern为cbc，text中满足条件的是abaacxbcbbbbacc下划线部分。

# 输入描述:
# 多行，每行一个text和一个pattern，用空格分隔。
# 保证1<=|text|,|pattern|<=1000，Σ|text|,Σ|pattern|<=10000。

# 输出描述:
# 输出最短匹配序列起止位置（位置下标从0开始），用空格分隔。若有多个答案，输出起止位置最小的答案；若无满足条件的答案，则起止均为-1。
import re

class Solution:

    def tackle(self,text,pattern):
        start,end=0,0
        text=text.lower()
        start=text.find(pattern)
        re.findall(pattern,text)
        print(text,pattern)
        return start,end

s=Solution()
start,end=s.tackle('abAacxbcbbbbacc',r'c*bc')
print(start,end)


# 输入例子1:
# abaacxbcbbbbacc cbc
# abc x
# aaabcac ac

# 输出例子1:
# 4 7
# -1 -1
# 5 6