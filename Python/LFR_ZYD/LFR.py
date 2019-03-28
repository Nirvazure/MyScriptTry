import pandas as pd 
import numpy as np
import matplotlib.pyplot as plt
import webbrowser

class LFR_DataProvider():
    """Summary of class here.

    Giving a path file....
    Return a dataframe objects describe the path....

    Attributes:
        data: A pandas dataframe object.
    """
    data=pd.DataFrame()
    
    def __init__(self,filename):
        """Inits SampleClass with blah."""
        
        self.data = pd.read_table(filename,'\s',header=None)
        self.data.columns = ['timescrape','longitude','latitude']
        self.data['longitude']=round(self.data['longitude'],6)
        self.data['latitude']=round(self.data['latitude'],6)

#差分代码段
def chafen(data):
    """Performs operation blah."""
    temp=data.diff()
    return temp

def to_csv(targetfile,data):
    data.to_csv(targetfile,index=False)

#画图
def paint(data):
    x = np.array(data['longitude']/1000000)
    y = np.array(data['latitude']/1000000)
    plt.scatter(x,y)
    plt.axis([0, 150, 0, 50])
    plt.show()

def createAMapCSV(targetFile,data,url,style=1):
    f1 = open(targetFile, 'w')
    f1.writelines("var citys = [\n")
    for i in range(len(data)):
        str_i='{"lnglat":['+str(data['longitude'][i])+','+str(data['latitude'][i])+'],"name":"2017-10-01 00:00:22","style":'+str(style)+'},'
        f1.writelines("\t"+str_i+"\n")
    f1.writelines("]")
    webbrowser.open(url)

# def haversine(lng1, lat1, lng2, lat2): # 经度1，纬度1，经度2，纬度2 （十进制度数） 
    # """ 
    # Calculate the great circle distance between two points on the earth (specified in decimal degrees) 
    # """
    # # 将十进制度数转化为弧度 
    # lng1, lat1, lng2, lat2 = map(radians, [lng1, lat1, lng2, lat2]) 
    # # haversine公式 
    # dlng = lng2 - lng1 
    # dlat = lat2 - lat1  
    # r = 6371000.0 # 地球平均半径，单位为公里 
    # dis = 2 * asin(sqrt(sin(dlat/2)**2 + cos(lat1) * cos(lat2) * sin(dlng/2)**2)) * r
    # return dis

def FindPathByPoint(x,y,data,num=20):
    pass