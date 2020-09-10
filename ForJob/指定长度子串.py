# 给定一个字符串，输出所有指定长度为n的子串，没有则输出-1
# 输入描述:
# 输入第一行一个字符串，如：“1234567890”
# 输入第二行一个数字是n，如5
# 输出描述:
# 输出所有长度为n的子串，如“12345”，“23456”，“34567”，“45678”，“56789”
# 输入例子1:
# 123456789
# 5
# 输出例子1:
# 12345 23456 34567 45678 56789

class Solution:

    resStrs=[]

    def tackle(self,str,n):
        i=0
        while(i+n<=len(str)):
            self.resStrs.append(str[i:n+i])
            i+=1
        if(len(self.resStrs)>0):
            return self.resStrs
        else:
            return -1

s=Solution()
a=s.tackle('12345678',1)
print(a)