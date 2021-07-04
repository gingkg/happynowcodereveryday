// HJ103_RedraimentMove.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
题目描述
Redraiment是走梅花桩的高手。Redraiment可以选择任意一个起点，从前到后，但只能从低处往高处的桩子走。他希望走的步数最多，你能替Redraiment研究他最多走的步数吗？

本题含有多组样例输入


输入描述:
输入多组数据，1组有2行，第1行先输入数组的个数，第2行再输入梅花桩的高度

输出描述:
一组输出一个结果

示例1
输入
6
2 5 1 5 4 5
3
3 2 1
输出
3
1
说明
6个点的高度各为 2 5 1 5 4 5
如从第1格开始走,最多为3步, 2 4 5
从第2格开始走,最多只有1步,5
而从第3格开始走最多有3步,1 4 5
从第5格开始走最多有2步,4 5
所以这个结果是3。
*/


#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

class Solution {
public:
    int PlumPile(vector<int>& nums)
    {
        int n = nums.size();
        if (n < 2) return n;
        vector<int> dp(n,1);
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j] > nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        auto maxPosition = max_element(dp.begin(), dp.end());
        return *maxPosition;
    }
};

int main()
{
    int n;
    vector<int> nums;
    vector<int> res;
    Solution S;
    while (cin >> n) {
        if (n < 0) break;
        nums.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        res.push_back(S.PlumPile(nums));
    }

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }

}

