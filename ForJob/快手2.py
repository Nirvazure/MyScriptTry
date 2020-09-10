from itertools import combinations as cb

dict = {'2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl',
        '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'}

number = input()
values = []
for num in number:
    values.append(dict[num])

a = list(cb(values, 3))
print(a)
