"""
问题描述：
这一题主要是字符串处理的一些问题，涉及到一些简单的处理规则，需要用到正则表达式和简单的逻辑判断
规则1匹配的模式：r''/(.+)1{2,}/''
规则2匹配的模式：r''/(.+)1{2,}/''
找到字符串的这种模式修改这种模式
"""

import re

pattern1 = r''/(.+)1{2,}/''
pattern1_new = r''/(.+)1{1,}/''
pattern2 = r''/(.+)1{2,}/''
pattern2 = r''/(.+)1{1,}/''

def wangdachui(originStrs->List){
    temp=re.search(pattern1,s)
    for i in range(len(temp.group)):
        tempStr=temp.group[i]
        re.sub(pattern1, pattern1_new, tempStr, count=1)
    temp=re.search(pattern2,s)
    for i in range(len(temp.group)):
        tempStr=temp.group[i]
        re.sub(pattern2, pattern2_new, tempStr, count=1)
    return(newStrs->List)
}

if __name__ == '__main__':
    N=input()
    originStrs=[]
    for(i=0;i<N;i++){
        originStr=input()
        originStrs.append(originStr)
    }
    
    newStr=wangdachui(originStrs)
    print([wangdachui(os)for os in originStr])

    