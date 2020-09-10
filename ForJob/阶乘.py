# 求任一正整数的阶乘（注意：是任意正整数）
# 该正整数不大于1000。
# 输入描述:输入一个正整数
# 输出描述:输出一个正整数

def tackle(n:int)->int:
    if(n>1000):
        return -1
    if(n==1):
        ans=1
    else:
        ans=n*tackle(n-1)
    return ans

n=input()
ans=tackle(int(n))
print(ans)

# 输入例子1:
# 3
# 输出例子1:
# 6
# 输入例子2:
# 10
# 输出例子2:
# 3628800