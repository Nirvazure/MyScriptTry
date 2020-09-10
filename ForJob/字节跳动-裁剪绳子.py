"""
算法描述：
可以先考虑对这些绳子的长度进行排序
    1 如果M值小于等于N值，选择N里面前M条以最小长度进行裁切即可
    2 如果M值大于N值，算出M-N的差C，N中从大到小第C长的绳子的一般就是M跟绳子的长度
"""
def cutRope(oriRopes,M):
    MLen=-1
    oriRopes=oriRopes.order()
    N=len(OriRopes)
    if(M<=N):
        Mlen=oriRopes[M]
    else:
        Mlen=originRopes[M-N]/2
    return Mlen

if __name__ == '__main__':
    N=input("请输入原始的绳子数目")
    M=input("请输入需要的绳子数目")
    oriRopes=[]
    for i in range(N):
        iRope=input("请输入第"+i+"跟绳子的长度")
        oriRopes.append(iRope)
    
    MLen=cutRope(oriRopes,M)
    print("可以裁剪出"+M+"根长度为"+Mlen+"的绳子")

    