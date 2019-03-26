import pandas as pd 
import matplotlib.pyplot as plt
import matplotlib
import numpy as np  
from pylab import mpl
from matplotlib.animation import FuncAnimation

carfile='浙BF9790.txt'

#本代码先把所有真假点筛出来，用真值点周边的数据作为轨迹输入，现在字典里面找到停靠点并画出，动态画轨迹
#数据来源为2018年1月的停靠点，轨迹为严博林给的1000真车轨迹在100个停留点的周边轨迹
#重复播放还是有问题，轨迹什么时候画完并不明确

#car_path,true_points,false_points,all_staypoints
f=open(carfile,encoding='utf-8')
car_path=pd.read_csv(f)
#底下视情况改
car_path.columns=['timestamp','longitude','latitude']
true_points=pd.read_csv('src/true_unload_points.csv')
false_points=pd.read_csv('src/false_unload_points.csv')
all_stay_points=pd.read_csv('src/201801_9404cars_allStayPoints.txt',header=None)
all_stay_points.columns=['longitude','latitude','start_time','end_time','num_data','plate']

def select_staypoints_by_car(carname,all_stay_points):
    df_selectCar=all_stay_points[all_stay_points['plate']==carname]
    return df_selectCar

carname=carfile[0:-4]
staypoints_bycar = select_staypoints_by_car(carname,all_stay_points)
print(staypoints_bycar)

#截止上面，所有的数据准备完了，准备画图
mpl.rcParams['font.sans-serif'] = ['Microsoft YaHei'] # 指定默认字体
mpl.rcParams['axes.unicode_minus'] = False # 解决保存图像是负号'-'显示为方块的问题

fig, ax = plt.subplots()
xdata, ydata = [], []
ln, = plt.plot([], [], 'bo', animated=True,lw=0.04)
p_x=np.array(car_path['longitude'])
p_y=np.array(car_path['latitude'])
#确定X，Y轴的范围
def init():
    #为请屏幕做准备
    xdata, ydata = [], []
    ln.set_data(xdata, ydata)
    #+10扩大点范围,regulation是调节显示范围的
    regulation=0.05
    ax.set_xlim(np.min(car_path['longitude']-regulation),np.max(car_path['longitude'])+regulation)
    ax.set_ylim(np.min(car_path['latitude']-regulation),np.max(car_path['latitude'])+regulation)
    
    tp_x=np.array(true_points['longitude'])
    tp_y=np.array(true_points['latitude'])
    plt.scatter(tp_x,tp_y,s=50,c='g')

    fp_x=np.array(false_points['longitude'])
    fp_y=np.array(false_points['latitude'])
    plt.scatter(fp_x,fp_y,s=50,c='r')

    sp_x=np.array(staypoints_bycar['longitude'])
    sp_y=np.array(staypoints_bycar['latitude'])
    plt.scatter(sp_x,sp_y,s=50,c='y')
    plt.legend(['path','true','flase','stay'])
    return ln,
#提供Animate调用
def update(i):
    xdata.append(p_x[i])
    ydata.append(p_y[i])
    ln.set_data(xdata, ydata)
    print(i)
    return ln,

ani = FuncAnimation(fig, update, frames=len(car_path),init_func=init,interval=2,blit=True,repeat=False)
plt.title(carname)
# plt.savefig('./img-1/'+root[7:]+'_'+pathList[i][0:-4]+'.png')
plt.show()
plt.close(0)