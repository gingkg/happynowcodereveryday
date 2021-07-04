// HJ31_InvertWord.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
题目描述
对字符串中的所有单词进行倒排。

说明：

1、构成单词的字符只有26个大写或小写英文字母；

2、非构成单词的字符均视为单词间隔符；

3、要求倒排后的单词间隔符以一个空格表示；如果原字符串中相邻单词间有多个间隔符时，倒排转换后也只允许出现一个空格间隔符；

4、每个单词最长20个字母；

输入描述:
输入一行以空格来分隔的句子

输出描述:
输出句子的逆序

示例1
输入
I am a student
输出
student a am I

示例2
输入
$bo*y gi!r#l
输出
l r gi y bo
*/


#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string InvertWord(string raw) {
        string res = "";
        int n = raw.size();
        int left = n - 1, right;
        bool flag = false;
        while (left >= 0) {
            char cur = raw[left];
            if (flag) {
                if (!((0 <= (cur - 'A') && (cur - 'A') < 26) || (0 <= (cur - 'a') && (cur - 'a')  < 26))) {
                    res = res + raw.substr(left + 1, right - left) + " ";
                    flag = false;
                }
            }
            else {
                if ((0 <= (cur - 'A') && (cur - 'A') < 26) || (0 <= (cur - 'a') && (cur - 'a') < 26)) {
                    right = left;
                    flag = true;
                }
            }
            left--;
        }

        if (flag) {
            res = res + raw.substr(0, right - left);
        }
        else {
            res = res.substr(0, res.size() - 1);
        }
        return res;
    }
};


int main()
{
    Solution S;
    string raw;
    getline(cin, raw);
    cout << S.InvertWord(raw) << endl;
}

