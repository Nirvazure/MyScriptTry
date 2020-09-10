""" ## 无人机探测策略

## Solution1

- 利用十字区域单边可以横跨三个矩形
- 有长短边的概念

### 出发点：[1,0] or [0,1]

### 飞行线路：

短边单步行进，短边尽头横跨长边三个单位掉头（不能横跨时，如果矩形还没访问完，减少长边跨幅，直到全地图访问）

### 拍摄时机

短边单步跳转

## Solution2

以锯齿状，用交错的形式，最大程度上利用十字形的优势，减少拍照时间

### 出发点：[0,0]

### 飞行线路：

x,y->(x+2,y+1)--x>>y
x,y->(x+1,y+2)--y>>x

### 拍摄时机

每次跳转都进行拍摄

## Solution3

局部最优的一个思路,利用计算机处理问题的特性

### 出发点：

地图上任意一点，需要额外的维护一张表

### 飞行线路：

剩余点集中，有最多空值的点，不断更新，直到所有点都被访问到

### 拍摄时机

每次跳转都进行拍摄

## Review

item | Solution1 | Solution2|Solution3|
-|-|-|-
返回出发点？？？ | Y | Y- |Y-
最终地图完整？ | Y | Y- |
减少拍照次数，减少冗余数据|+ | ++ |
形状全覆盖|Y|N| """

class Solution:

    int start_x, start_y
    path = []
    time = []

    def getInput(self):
        inInfo = [int(temp) for temp in input('please enter N & K\n').split()]
        n, k = inInfo[0], inInfo[1]
        inData = [int(temp)
                  for temp in input('please enter Numbers\n').split()]
        datas = []
        for i in range(n):
            nums.append(inData[i])
        return n, k, datas

    def __init__(self, x, y, path, time):
        self.start_x = x
        self.start_y = y
        self.path = path
        self.time = time

    def Data2Map(self,paths,map):
        for i in range(len(paths)):
            x=path[i][0]
            y=path[i][1]
            if(map[x][y]!=NULL):



class Plane:

    def __init__(self, N, M):

    def Fly_Map(M, N):
        data = []
        data.add('GGGGG')


solution1 = Solution(0, 0, [1, 3, 4], [1, 4, 5])
solution2 = Solution(N/2, M/2, [1], [22])


paths=[[1,0,''],[1,1],[1,2],[1,3],[4,0],[4,1],[4,2],[4,3]]