// HJ57.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
描述
输入两个用字符串表示的整数，求它们所表示的数之和。
字符串的长度不超过10000。
本题含有多组样例输入。
输入描述：
输入两个字符串。保证字符串只含有'0'~'9'字符

输出描述：
输出求和后的结果

示例1
输入：
9876543210
1234567890

输出：
11111111100

*/

#include <iostream>
#include <string>
using namespace std;

string fun(string& num1, string& num2)
{
    // 补0
    int n = num1.size();
    int m = num2.size();
    if (n < m) {
        for (int i = 0; i < m - n; i++) {
            num1 = "0" + num1;
        }
    }
    else if (m < n) {
        for (int i = 0; i < n - m; i++) {
            num2 = "0" + num2;
        }
    }


    string res = "";
    int carryBit = 0;
    for (int i = num1.size() - 1; i >= 0; i--) {
        int ans = (num1[i] - '0') + (num2[i] - '0') + carryBit;
        if (ans >= 10) {
            carryBit = ans / 10;
            ans = ans % 10;
        }
        else {
            carryBit = 0;
        }
        res = to_string(ans) + res;
    }
    if (carryBit != 0) {
        res = to_string(carryBit) + res;
    }

    return res;
}


int main()
{
    string num1;
    string num2;
    num1 = "623192091";
    num2 = "14426202982932";

    cout << fun(num1, num2) << endl;


    /*while (getline(cin, num1), getline(cin, num2)) {
        cout << fun(num1, num2) << endl;
    }*/
}
