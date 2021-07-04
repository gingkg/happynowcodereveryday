// HJ108_LeastCommonMultiple.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
题目描述
正整数A和正整数B 的最小公倍数是指 能被A和B整除的最小的正整数值，设计一个算法，求输入A和B的最小公倍数。

输入描述:
输入两个正整数A和B。

输出描述:
输出A和B的最小公倍数。

示例1
输入

5 7
输出
35
*/


#include <iostream>
using namespace std;

class Solution {
public:
    int LeastCommonMultiple(int a, int b) {
        int res = 0;
        int A = max(a, b);
        int B = min(a, b);
        for (int i = 1; i <= B; i++) {
            res = A * i;
            if (res % B == 0) {
                return res;
            }
        }
        return res;
    }
};

int main()
{
    int a, b;
    cin >> a >> b;
    Solution S;
    cout << S.LeastCommonMultiple(a, b) << endl;
}

