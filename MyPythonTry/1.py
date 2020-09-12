a=1.23455566
result=round(a,15)
print(result)

# 取出python和life之间的字串，group的概念要了解，正则要了解
import re
s = 'life is short,i use python'
# method1
r = re.search('life(.*)python',s)
print(r.group(1))
# method2
r = re.findall('life(.*)python',s)
print(r)