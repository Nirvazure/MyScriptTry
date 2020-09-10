import pandas as pd
import numpy as np

lfr = "wepay_lfr.csv"
dfr = pd.read_csv(lfr)
dfr = dfr[['交易时间', '交易类型', '交易对方', '商品', '收/支', '金额(元)', '支付方式']]
# print(dfr['交易时间'][0:30])
print(dfr[dfr['交易类型'] == '微信红包'])
# print(dfr[dfr['交易对方'] == '蜜雪冰城'])
# inM = df[df['收/支'] == '收入']
# inM['金额(元)'].astype("int")
# print(outM['金额(元)'].sum())

# grouped = dfr.groupby('交易对方')
# print(grouped.agg(np.size))
# for name, group in grouped:

#     if len(group)>20:
#         print(name)
#         print(len(group))
#         print(group)
#         group['金额(元)'].astype("int")
#         print(group['金额(元)'].sum())

# hb = dfc[dfc['交易类型'] == '微信红包']
# print(df['支付方式'].drop_duplicates())
