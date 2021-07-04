// HJ107_Subtriplicate.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
题目描述
计算一个数字的立方根，不使用库函数。
保留一位小数。


输入描述:
待求解参数，为double类型（一个实数）

输出描述:
输入参数的立方根。保留一位小数。

示例1
输入

216
输出
6.0
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class Solution {
public:
    double Subtriplicate(double raw) {
        bool flag = raw >= 0 ? true : false;
        if (!flag) raw = -raw;
        double low, high, mid=1;
        if (raw >= 1) {
            low = 1;
            high = raw;
        }
        else {
            low = raw;
            high = 1;
        }

        while (high - low >= 0.001) {
            mid = low + (high - low) / 2;
            cout << low << " " << high << " " << mid << endl;
            double res = mid * mid * mid;
            if (abs(res - raw) < 0.001) {
                return flag ? mid : -mid;
            }
            else if (res < raw) {
                low = mid;
            }
            else {
                high = mid;
            }
        }
        return mid;
    }
};


int main()
{
    Solution S;
    double a;
    cin >> a;
    cout << fixed << setprecision(1) << S.Subtriplicate(a) << endl;
}




