import os
import random
f_list=os.listdir('c:\Users\Administrator\Desktop\TTTT\NISAN')
a=random.randint(100000,999999)
oldpath='d:/工作/myd_test/car7/'
newpath='d:/工作/myd_test/car7/'

for name in f_list:
    a=random.randint(1000000,9999990)
    os.renames(oldpath+name,newpath+'20180905_video_'+str(a)+'_car_7.jpg')
print('done!')

    
