import pandas as pd 
import matplotlib.pyplot as plt
import matplotlib
import numpy as np  
import os
import random
from pylab import mpl

mpl.rcParams['font.sans-serif'] = ['Microsoft YaHei'] # 指定默认字体
mpl.rcParams['axes.unicode_minus'] = False # 解决保存图像是负号'-'显示为方块的问题

def paint(root):
    pathList = os.listdir(root)

    point=root[7:].split('_')
    xi=float(point[0][1:])
    yi=float(point[1])

#     numList=[]#存放每段轨迹点的数目，放在图例的位置

    for i in range(len(pathList)):
        print(pathList[i],root)
        f = open(root+'/'+pathList[i],encoding='utf-8')
        df = pd.read_csv(f)

        x = np.array(df['longitude'])
        y = np.array(df['latitude'])
        
        num=df.iloc[:,0].size   #输出多少个点
        
        plt.figure(0) #这样存的是新图，和最后的close对应，没有这句会一直覆盖老图
        print(pathList[i][0:-4]+'-->'+str(num))
        plt.scatter(x,y,s=30,c=randomcolor())
        plt.scatter(xi,yi,s=40,c='k')
        plt.title(pathList[i][0:-4]+'   count:'+str(num)+'\npoint '+str(xi)[0:10]+'  '+str(yi)[0:9])#保留小数点后6位
        plt.legend(['path','point'])
        plt.savefig('./img-1/'+root[7:]+'_'+pathList[i][0:-4]+'.png')
        
        plt.close(0)

def randomcolor():
    colorArr = ['1','2','3','4','5','6','7','8','9','A','B','C','D','E','F']
    color = ""
    for i in range(6):
        color += colorArr[random.randint(0,14)]
    return "#"+color

#调用部分
listi=os.listdir('out-2')
for i in range(len(listi)):
    paint('./out-2/'+listi[i])