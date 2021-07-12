/*
 * HJ85 最长回文子串
给定一个仅包含小写字母的字符串，求它的最长回文子串的长度。
所谓回文串，指左右对称的字符串。
所谓子串，指一个字符串删掉其部分前缀和后缀（也可以不删）的字符串
（注意：记得加上while处理多个测试用例）

输入描述：
输入一个仅包含小写字母的字符串

输出描述：
返回最长回文子串的长度

示例1
输入：
cdabbacc

输出：
4

说明：
abba为最长的回文子串
*/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        // 构建新的字符串
        string sNew = "@#";
        for (unsigned int i = 0; i < s.size(); i++) {
            sNew.append(s, i, 1);
            sNew.append("#");
        }
        sNew.append("?");

        // 使用马拉车算法处理新的字符串
        vector<int> f(sNew.size(), 1);
        int iMax = 1, rMax = 1, ans = 1;
        for (int i = 2; i < int(sNew.size()) - 1; i++) {
            // 初始化f(i)
            f[i] = i > rMax ? 1 : min(f[2 * iMax - i], rMax - i + 1);
            // 中心扩展
            while (sNew[i + f[i]] == sNew[i - f[i]]) f[i]++;
            // 动态维护 iMax 和 rMax
            if (i + f[i] - 1 > rMax) {
                iMax = i;
                rMax = i + f[i] - 1;
            }
            if (f[i] > f[ans]) {
                ans = i;
            }
        }
        sNew = sNew.substr(ans - f[ans] + 1, 2 * f[ans] - 1);
        sNew.erase(remove(sNew.begin(), sNew.end(), '#'), sNew.end());

        return sNew.size();
    }
};


int main()
{
    string str;
    Solution S;
    while(getline(cin, str)){
        cout << S.longestPalindrome(str) << endl;
    }
}

