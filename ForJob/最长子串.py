#!/bin/python
# -*- coding: utf8 -*-
import sys
import os
import re

def longestSubStrLength(s1, s2):
    lstr1=len(s1)
    lstr2=len(s2)
    record=[[0 for i in range(lstr2+1) for j in range(lstr1+1)]]
    maxNum=0
    p=0
    for i in range(lstr1):
        for j in range(lstr2):
            if s1[i]==s2[j]:
                record[i+1][j+1]=record[i][j]+1
                if record[i+1][j+1]>maxNum:
                    maxNum=record[i+1][j+1]
                    p=i+1
    return maxNum


#******************************结束写代码******************************


try:
    _s1 = input()
except:
    _s1 = None

try:
    _s2 = input()
except:
    _s2 = None

  
res = longestSubStrLength(_s1, _s2)

print(str(res) + "\n")