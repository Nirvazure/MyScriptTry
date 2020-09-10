# def number_of_1(n):
#     a = bin(n)
#     count = 0
#     for i in str(a):
#         if(i == '1'):
#             count += 1
#     return count


# ans = number_of_1(8)
# print(ans)

def smallestRange():
    k = int(input())
    a = list(map(int, input().split()))
    return tackle(k, a)


def tackle(k: int, a: list)->int:
    ans = 1000
    a = sorted(a)
    i = 0
    j = len(a)-1
    while(i <= j):
        cha = abs((a[i]+k)-(a[j]-k))
        if(cha < ans):
            ans = cha
        i += 1
        j -= 1
    return ans


a = tackle(3, [7, 4, 3, 9, 2])
print(a)
