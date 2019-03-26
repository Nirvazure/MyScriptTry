import pandas as pd 
import numpy as np 
import os
import time
from math import pi,sin,cos,asin,sqrt,asin,pow

#1
#输入：root文件夹里面是命名为点的文件
#输出：out-1下文件夹，里面放的是车
root = './src/data-ybl/desttrue/'
filelist = os.listdir(root)

for i in range(len(filelist)):
    temppath = './out-1/'+filelist[i][0:-4]
    os.makedirs(temppath)
    f = open(root+filelist[i],encoding='utf-8')
    df = pd.read_csv(f,sep='\s')    
  
    df.columns=['longitude','latitude','timestamp','dist','plate']  
    
    groups = df.groupby(['plate'])
    for group in groups:
        df=group[1][['longitude','latitude','timestamp','dist']]
        df['time'] = df['timestamp'].apply(lambda x:time.strftime("%Y-%m-%d %H:%M:%S", time.localtime((x))))
        # df[['longitude','latitude','timestamp','dist']]=df[['longitude','latitude','timestamp','dist']].diff()
        df[['timestamp1','dist']]=df[['timestamp','dist']].diff()
        df.to_csv(temppath+'/'+str(group[0][0:-4]) + '.csv', index=False)

#2
import os,shutil

def mymovefile(srcfile,dstfile):
    if not os.path.isfile(srcfile):
        print ("%s not exist!"%(srcfile))
    else:
        fpath,fname=os.path.split(dstfile)    #分离文件名和路径
        if not os.path.exists(fpath):
            os.makedirs(fpath)   
        try:             #创建路径
            shutil.move(srcfile,dstfile)          #移动文件
        except IOError:
            print ("Error: 没有找到文件或读取文件失败")
        print ("move %s -> %s"%( srcfile,dstfile))

def mycopyfile(srcfile,dstfile):
    if not os.path.isfile(srcfile):
        print ("%s not exist!"%(srcfile))
    else:
        fpath,fname=os.path.split(dstfile)    #分离文件名和路径
        if not os.path.exists(fpath):
            os.makedirs(fpath)                #创建路径
        shutil.copyfile(srcfile,dstfile)      #复制文件
        print ("copy %s -> %s"%( srcfile,dstfile))

# srcfile='/Users/xxx/git/project1/test.sh'
# dstfile='/Users/xxx/tmp/tmp/1/test.sh'

# mymovefile(srcfile,dstfile)
root = '可用的单次轨迹'
oldimgs = os.listdir(root)
oldpaths=[]
# print(oldimgs)
for i in range(len(oldimgs)):
    a=oldimgs[i].replace('_','/')
    b=a.replace('/','_',1)
    c='out-2/'+b.replace('png','csv')
    oldpaths.append(c)
    # print(c)
print(oldpaths)

for i in range(len(oldpaths)):
    print(oldpaths[i])
    a=oldpaths[i][6:]
    b=a.replace('/','-')
    print(b)
    mymovefile(oldpaths[i],'out-4/'+b)

#3
import os
import pandas as pd 

root = 'out-1'
pointlist=os.listdir(root)
new_path=[]
for i in range(len(pointlist)):
    temppath = './out-2/'+pointlist[i]
    os.makedirs(temppath)
    new_path.append('./'+root+'/'+pointlist[i])
print(new_path)

new2_path=[]
for i in range(len(new_path)):
    carlist=os.listdir(new_path[i])
    for j in range(len(carlist)):
        new2_path.append(new_path[i]+'/'+carlist[j])

for i in range(len(new2_path)):
    print(new2_path[i])   

    f = open(new2_path[i],encoding='utf-8')
    df = pd.read_csv(f)
    
    df1=df[df['timestamp1']>40000]
    index = df1.index
    a=list(index)
    a.append(len(df))

    for j in range(len(a)):
        print(a[j])
        if j==0:
            data = df.iloc[j:a[j],:]
        else:
            data = df.iloc[a[j-1]:a[j],:]
        # data.drop()
        print(new2_path[i][8:-4])
        data.to_csv('./out-2/'+new2_path[i][8:-4]+'-'+str(j)+'.csv')


#round函数
round()
len()
if(bool1 and bool2):
    doSth

#字符切片
filelist[i][0:-4]

df.to_csv('root/filename.csv',index=False)

root = 'true_csv/'
truePointFiles = os.listdir(root)
fileList=[]
for i in range(len(truePointFiles)):
    ft=root+truePointFiles[i]
    calTimeFeature(ft)
    input()

#文件打开
filename=''
file = open(filename,encoding='utf-8')
#获取到了df对象
df = pd.read_csv(file,header=None)
df=df[['index1','index2']]
#对df列集合的操作
df.columns=['index1','index2']#给列起名字
#对df对象的操作
df=df[['index1','index2']].astype(int)#给列更改类型
df=df[['index1','index2']].round(6)#对选中列保留6位小数 
df.drop(['index1','index2'],axis=1)
df.diff(axis=1)['index']
df['index'] = df['index'].apply(lambda x:f(x))

[]=str.split('_')

cars=df.groupby('plate')
    print('该点在2018-01的时间内\t经过车辆数：',len(cars))
    for name,group in cars:
        print(name+'\t',len(group),'次\t',int(group['duration'].mean()),'时')
    print('平均停留时间为：',df['duration'].mean(),'小时')
    print('最长停留时间：',df['duration'].max(),'小时')
    print('最短停留时间:',df['duration'].min(),'小时')
    print('停留半天的车辆行为次数：',len(df[df['duration']<=12]))
    print('停留半天到一天的车辆行为次数:',len(df[df['duration']<=24])-len(df[df['duration']<=12]))
    print('停留一天以上的车辆行为次数：',len(df[df['duration']>24]))