// HJ102_CharStatistic.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
字符统计

描述
输入一个只包含小写英文字母和数字的字符串，按照不同字符统计个数由多到少输出统计结果，如果统计的个数相同，则按照ASCII码由小到大排序输出。
本题含有多组样例输入

输入描述：
一个只包含小写英文字母和数字的字符串。

输出描述：
一个字符串，为不同字母出现次数的降序表示。若出现次数相同，则按ASCII码的升序输出。

示例1
输入：
aaddccdc
1b1bbbbbbbbb
输出：
cda
b1
说明：
第一个样例里，c和d出现3次，a出现2次，但c的ASCII码比d小，所以先输出c，再输出d，最后输出a.
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;


class Solution
{
public:
    string CharStatistic(string& raw) {
        int n = raw.size();
        string res = "";
        unordered_map<char, int> index;
        vector<char> cnt;
        
        for (int i = 0; i < n; i++) {
            ++index[raw[i]];
        }

        for (unordered_map<char, int>::iterator iter = index.begin(); iter != index.end();iter++) {
            cnt.emplace_back(iter->first);
        }

        sort(cnt.begin(), cnt.end(),
            [&](const char& a, const char& b) {
                if (index[a] == index[b]) return a < b;
                return index[a] > index[b];
            });

        for (char c : cnt) {
            res = res + c;
        }

        return res;
    }
};


int main()
{
    Solution S;
    string raw;
    vector<string> res;
    while (cin >> raw) {
        res.push_back(S.CharStatistic(raw));
    }

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
}

