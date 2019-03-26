import os
import random
import matplotlib
import numpy as np
import pandas as pd 
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
from pylab import mpl
import time
import sys

true_points=pd.read_csv('src/true_unload_points.csv')
false_points=pd.read_csv('src/false_unload_points.csv')
all_stay_points=pd.read_csv('src/201801_9404cars_allStayPoints.txt',header=None)
all_stay_points.columns=['longitude','latitude','start_time','end_time','num_data','plate']

mpl.rcParams['font.sans-serif'] = ['Microsoft YaHei'] # 指定默认字体
mpl.rcParams['axes.unicode_minus'] = False # 解决保存图像是负号'-'显示为方块的问题

def select_staypoints_by_car(carname,all_stay_points):
    df_selectCar=all_stay_points[all_stay_points['plate']==carname]
    return df_selectCar

def paint(dataframe,delay,color):
    fig, ax = plt.subplots()
    xdata, ydata = [], []
    ln, = plt.plot([], [], c=color,marker='o', animated=True)

    x = np.array(dataframe['longitude'])
    y = np.array(dataframe['latitude'])

    #确定X，Y轴的范围
    def init():
        temp=0.001 #调节
        ax.set_xlim(np.min(x-temp),np.max(x+temp))
        ax.set_ylim(np.min(y-temp),np.max(y)+temp)
        
        ax.grid(True,color='k',linestyle='-.',linewidth=0.5)

        tp_x=np.array(true_points['longitude'])
        tp_y=np.array(true_points['latitude'])
        plt.scatter(tp_x,tp_y,s=30,c='g')

        fp_x=np.array(false_points['longitude'])
        fp_y=np.array(false_points['latitude'])
        plt.scatter(fp_x,fp_y,s=30,c='r')

        sp_x=np.array(staypoints_bycar['longitude'])
        sp_y=np.array(staypoints_bycar['latitude'])
        plt.scatter(sp_x,sp_y,s=40,c='y')

        plt.xlabel('longitude')
        plt.ylabel('latitude')
        plt.legend(['path','true','flase','stay'])
        return ln,
    #提供Animate调用
    def update(i):
        xdata.append(x[i])
        ydata.append(y[i])
        #进度条可注释,进度条会影响画图的速度
        # bar_length=70   #进度条长度
        # hashes = '#' * int(i/(len(x)-1) * bar_length)
        # spaces = ' ' * (bar_length - len(hashes))
        # sys.stdout.write("\rPercent: [%s] %d%%"%(hashes + spaces, int(i/(len(x)-1)*100)))
        # sys.stdout.flush()
        # time.sleep(1)
        #直接显示
        print(i,len(x))
        ln.set_data(xdata, ydata)

        return ln,
    #不知道为啥不能重复
    ani = FuncAnimation(fig, update, frames=len(x),init_func=init,interval=delay,blit=True,repeat=False)
    ani.save('basic_animation.mp4', fps=2, extra_args=['-vcodec', 'libx264'])
    print('视频文件已经成功生成')
    plt.show()

def randomcolor():
    colorArr = ['1','2','3','4','5','6','7','8','9','A','B','C','D','E','F']
    color = ""
    for i in range(6):
        color += colorArr[random.randint(0,14)]
    return "#"+color

root = 'out-1/'
pointList = os.listdir(root)
for i in range(len(pointList)):
    carList = os.listdir(root+pointList[i])
    print(pointList[i])
    for j in range(len(carList)):
        f = open(root+pointList[i]+'/'+carList[j],encoding='utf-8')
        df = pd.read_csv(f)
        print('\n'+carList[j][:-4])
        staypoints_bycar = select_staypoints_by_car(carList[j][:-4],all_stay_points)
        paint(df,10,randomcolor())
