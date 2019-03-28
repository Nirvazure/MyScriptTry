import numpy as np

filename = './1.txt'

a = np.loadtxt(filename,dtype=np.str)
print(a[0:8])