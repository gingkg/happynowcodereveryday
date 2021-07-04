// HJ30.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <string>
#include <algorithm>
#include<bitset>
using namespace std;

// 4位倒序
uint16_t bin4_rev(uint16_t data)
{
    data = ((data & 0xC) >> 2) | ((data & 0x3) << 2);
    data = ((data & 0xA) >> 1) | ((data & 0x5) << 1);
    return data;
}


// 8位的倒序
uint16_t bin8_rev(uint16_t data)
{
    data = ((data & 0xf0) >> 4) | ((data & 0x0f) << 4);
    data = ((data & 0xCC) >> 2) | ((data & 0x33) << 2);
    data = ((data & 0xAA) >> 1) | ((data & 0x55) << 1);
    return data;
}

//16位的倒序：
uint16_t bin16_rev(uint16_t us_DataIn)
{
    uint16_t us_Data = us_DataIn;
    us_Data = ((us_Data & 0xFF00) >> 8) | ((us_Data & 0x00FF) << 8);
    us_Data = ((us_Data & 0xF0F0) >> 4) | ((us_Data & 0x0F0F) << 4);
    us_Data = ((us_Data & 0xCCCC) >> 2) | ((us_Data & 0x3333) << 2);
    us_Data = ((us_Data & 0xAAAA) >> 1) | ((us_Data & 0x5555) << 1);

    return us_Data;
}

uint32_t bin32_rev(uint32_t x)
{
    x = (x & 0x55555555) << 1 | (x & 0xAAAAAAAA) >> 1;
    x = (x & 0x0F0F0F0F) << 4 | (x & 0xF0F0F0F0) >> 4;
    x = (x & 0x00FF00FF) << 8 | (x & 0xFF00FF00) >> 8;
    x = (x & 0x0000FFFF) << 16 | (x & 0xFFFF0000) >> 16;

    return x;
}


string fun(string& str1, string& str2)
{
    string str = str1 + str2;
    //     cout << str << endl;
    string str3 = "", str4 = "";
    for (int i = 0; i < str.size(); i++)
    {
        if (i % 2 == 0) {
            str3.push_back(str[i]);
        }
        else {
            str4.push_back(str[i]);
        }
    }
    sort(str3.begin(), str3.end());
    sort(str4.begin(), str4.end());

    //     cout << str3 << endl;
    //     cout << str4 << endl;

        // 分别转换
    for (char& c : str3) {
        uint16_t a = 16;
        if (48 <= c && c <= 57) a = c - 48;
        if (65 <= c && c <= 70) a = (c - 65) + 10;
        if (97 <= c && c <= 102) a = (c - 97) + 10;
        if (a < 16)
        {
            // 转换
            a = bin4_rev(a);
            if (a < 10) {
                c = '0' + a;
            }
            else {
                c = 'A' + (a - 10);
            }
        }
    }
    for (char& c : str4) {
        uint16_t a = 16;
        if (48 <= c && c <= 57) a = c - 48;
        if (65 <= c && c <= 70) a = (c - 65) + 10;
        if (97 <= c && c <= 102) a = (c - 97) + 10;
        if (a < 16)
        {
            // 转换
            a = bin4_rev(a);
            if (a < 10) {
                c = '0' + a;
            }
            else {
                c = 'A' + (a - 10);
            }
        }
    }

    //     cout << str3 << endl;
    //     cout << str4 << endl;

        // 合并
    for (int i = 0; i < str.size(); i++) {
        if (i % 2 == 0) {
            str[i] = str3[i / 2];
        }
        else {
            str[i] = str4[i / 2];
        }
    }
    return str;
}


int main()
{
    uint16_t data = 0b1110;
    uint16_t res = bin4_rev(data);
    cout << res << endl;

    string str1, str2;
    while (cin >> str1, cin >> str2)
    {
        //         cout << str1 << endl;
        //         cout << str2 << endl;
        cout << fun(str1, str2) << endl;
    }
}

