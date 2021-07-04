import sys


def fun(str1, str2):
    m = len(str1)
    n = len(str2)

    dp = [[0 for _ in range(n)] for _ in range(m)]

    # 初始化第一行和第一列
    for j in range(n):
        if str1[0] == str2[j]:
            dp[0][j] = 1
    for i in range(m):
        if str1[i] == str2[0]:
            dp[i][0] = 1

    # 动态规划
    for i in range(1, m):
        for j in range(1, n):
            if str1[i] == str2[j]:
                dp[i][j] = dp[i-1][j-1] + 1

    # 寻找最大值的位置
    pos1 = 0
    pos2 = 0
    value = 0
    if m < n:
        for i in range(m):
            for j in range(n):
                if dp[i][j] > value:
                    value = dp[i][j]
                    pos1 = i
                    pos2 = j
        return str1[pos1-value+1:pos1+1]
    elif m > n:
        for j in range(n):
            for i in range(m):
                if dp[i][j] > value:
                    value = dp[i][j]
                    pos1 = i
                    pos2 = j
        return str2[pos2-value+1:pos2+1]
    else:
        if pos1 <= pos2:
            return str1[pos1 - value + 1:pos1 + 1]
        else:
            str2[pos2 - value + 1:pos2 + 1]

i = 1
for line in sys.stdin:
    if i % 2 == 1:
        str1 = line
    else:
        str2 = line
        print(fun(str1, str2))
    i = i + 1
