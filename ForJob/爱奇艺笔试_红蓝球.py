import sys

def tackle(red,blue)->int:
    ans=0
    total=red+blue
    while(red>0 and blue>0):
    1
    ans=red/total
    2
    pa=blue--/total--
    pb=blue--/total--
    pc1=red--/total--
    pc2=red--/total--
    p=pa*pb*pc1*1/2*(1/red)
    ans=0
    ans=3/7+4/7*3/6*2/5*3/4
    return round(ans,5)

if __name__ == '__main__':
    line=sys.stdin.readline().strip()
    values=list(map(int,line.split()))
    red=values[0]
    blue=values[1]
    ans=tackle(red,blue)
    print(ans)

    
"""
红蓝球题目描述：

同样是一个袋子里面有n个红球和m个蓝球
共有A，B，C三人参与游戏
三人按照A，B，C的顺序轮流操作
在每一回合中，A，B，C都会随机从袋子里面拿走一个球
然而真正分出胜负的只有A，B两个人
没错，C就是来捣乱的
他除了可以使得袋子里面减少一个球没有其他任何意义
而A，B谁 先拿到红球就可以获得胜利
但是由于C的存在，两人可能都拿不到红球，此时B获得胜利。

输入
输入仅包含两个整数n和m,表示红球和蓝球的数量，中间用空格隔开。(0<=n,m<=1000)

输出
请你输出A获胜的概率，结果保留5位小数。（四舍五入）


样例输入
1 1
样例输出
0.50000

提示
输入样例2
3 4
输出样例2
0.62857 
"""