class Solution:

    def getInput(self):
        m, n = map(int, input().split())
        # 正确性检查
        coins = list(map(int, input('请输入'+str(n)+'个数').split()))[0:4]
        amounts = []
        coinDict = {}
        for i in range(m):
            amounts.append(i+1)
        coins = sorted(list(coins), reverse=True)
        for coin in coins:
            coinDict[coin] = 0
        return amounts, coinDict

    def tackle(self, amounts, coinDict):
        for key in coinDict:
            count = 0
            print(key, ':', coinDict[key])
            for i in range(len(amounts)):

                if(key <= amounts[i]):
                    count = count+1
                    amounts[i] = amounts[i]-key
            coinDict[key] = count
            print(amounts)
            input()
        print(coinDict, amounts)


s = Solution()
# amounts, coins = s.getInput()
amounts = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
           11, 12, 13, 14, 15, 16, 17, 18, 19, 20]
coinDict = {10: 0, 5: 0, 2: 0, 1: 0}

s.tackle(amounts, coinDict)
