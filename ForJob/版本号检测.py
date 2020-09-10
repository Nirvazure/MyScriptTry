def sortVersion(s1, s2):
    lstr1=s1.split('.')
    lstr2=s2.split('.')
    for i in range(max(len(lstr1),len(lstr2))):
        if int(lstr1[i])<int(lstr2[i]):
            return s1+','+s2
        elif int(lstr1[i])==int(lstr2[i]):
            continue
        else:
            return s1+','+s2

s1='5.10'
s2='5.1.2'
ans=sortVersion(s1,s2)
print(ans)