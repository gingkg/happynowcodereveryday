// HJ20.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;


bool comp(string s1, string s2)
{
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            if (dp[i][j] >= 3) {
               /* cout << s1[i - 2] << " " << s2[j - 2] << endl;
                cout << s1[i - 1] << " " << s2[j - 1] << endl;
                cout << s1[i] << " " << s2[j] << endl;
                cout << dp[i - 2][j - 2] << " " << dp[i - 1][j - 1] << " " << dp[i][j] << endl;
                cout << i << " " << j << endl;
                cout << s1 << endl;
                cout << s2 << endl;*/
                return true;
            }
                
        }
    }
    return false;
}


bool fun(string& str)
{
    // 长度超过8位
    if (str.size() <= 8) return false;
    // 包括大小写字母.数字.其它符号,以上四种至少三种
    vector<int> flag(4, 0);
    for (char c : str) {
        if (65 <= c && c <= 90) {
            flag[0] = 1;
        }
        else if (97 <= c && c <= 122) {
            flag[1] = 1;
        }
        else if (48 <= c && c <= 57) {
            flag[2] = 1;
        }
        else {
            flag[3] = 1;
        }
    }
    if (accumulate(flag.begin(), flag.end(), 0) < 3) return false;

    // 不能有相同长度大于2的子串重复
    // 两个字符串是否存在相同子串，且这个子串长度大于等于3
    for (int k = 3; k <= str.size() - 3; k++) {
        if (comp(str.substr(0, k), str.substr(k, str.size() - k))) return false;
    }

    return true;
}



int main()
{
    string str;
    vector<string> raw = {
        "S^fc8G5-78hlgV3X#96C5+5$b7K4^!#(B39",
        "I)S)1p0485$-ot4N7A9Mc*N3#46^Hd)9)-^Z!J**",
        "F04bA$y6$1CAD4n)x1$9&",
        "80-~8$~%x-F12P",
        "@!7479Y^V^1$l*26x#2S9%Nx0H!dY78*w4Zl",
        "16@%^nju+4d04U4*)1l!5+g!^k+P#vq*r#&v2059PsJ",
        "4@M$68(Oh%!n%~9&08&Z@#+dN0&Z",
        "D*09R~G1-$7GB&()$b1h^A^1b",
        "80!2b^*t411699+^&4y@",
        "xZ44332BZ-Ck0+ko~19(w!%",
        ")3y@GT!(5V9G(8VeT+(tM3k4",
        "O1r#K$C804E8-41J8*&%#13603",
        "7v0T+6s!(7*)C4RX8*IB85yk+6&~#v6)q$+W3&8-8+",
        "jJ8~7125d@DGmk~^~m637B20!61M5NdY^9CU9%R$1&h53iO+",
        "831(l)8^$O+3T"
    };
    
    for(string s: raw)
    {
        if (fun(s)) {
            cout << "OK" << endl;
        }
        else {
            cout << "NG" << endl;
        }
    }

   /* while (getline(cin, str))
    {
        if (fun(str)) {
            cout << "OK" << endl;
        }
        else {
            cout << "NG" << endl;
        }
    }*/
}