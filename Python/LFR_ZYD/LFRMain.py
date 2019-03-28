import LFR
import pandas as pd 
import sys
import ast

def main():
    args = str(sys.argv)
    args = ast.literal_eval(args)
    if (len(args) < 2):
        print ("You have input less than the minimum number of arguments. Go back and read README.txt and do it right next time!")
    elif (args[1][-4:] != ".txt"):
        print ("Your training file (second argument) must be a .txt!")
    else: 
        filename = args[1]
        targetfile = './path_output/'+args[1][11:-4]+'.csv'
        mapfile = 'citys.js'

        lfr_tool = LFR.LFR_DataProvider(filename)
        data = lfr_tool.data
        print(data)
        LFR.to_csv(targetfile,data)
        #写入差分文件
        if ("-c" in args):
            temp = LFR.chafen(data)
            data3 = pd.concat([data,temp],axis=1)
            LFR.to_csv(targetfile,data3)
        #画图
        if ("-p" in args):
            LFR.paint(data)
        #详细信息
        if("-i" in args):
            print(data.describe())
        #生成地图csv
        if("-m" in args): 
            url = 'mass.html'
            LFR.createAMapCSV(mapfile,data,url)

if __name__ == "__main__":
	main()