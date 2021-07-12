/*
 * HJ82 将真分数分解为埃及分数
分子为1的分数称为埃及分数。现输入一个真分数(分子比分母小的分数，叫做真分数)，请将该分数分解为埃及分数。如：8/11 = 1/2+1/5+1/55+1/110。
注：真分数指分子小于分母的分数，分子和分母有可能gcd不为1！
如有多个解，请输出任意一个。
请注意本题含有多组样例输入！


输入描述：
输入一个真分数，String型

输出描述：
输出分解后的string

示例1
输入：
8/11
2/4

输出：
1/2+1/5+1/55+1/110
1/3+1/6

说明：
第二个样例直接输出1/2也是可以的
*/



#include <iostream>
#include <string>
#include <vector>
using namespace std;

string getResult(string str)
{
    string res = "";

    // 提取分子分母
    int pos = str.find('/');
    int member = atoi(str.substr(0, pos).c_str());
    int denominator = atoi(str.substr(pos+1, str.size()-pos-1).c_str());

    // 创建存储空间
    vector<int> denRes;
    int ans;

    // starting
    while(1){
        if(denominator % member == 0){
            ans = denominator / member;
            member = 1;
        }else{
            ans = denominator / member + 1;
        }
        if (member == 1){
            denRes.push_back(ans);
            break;
        }else{
            denRes.push_back(ans);
            member = member*ans - denominator;
            denominator = denominator * ans;
            if(member == 3 && denominator % 2 == 0){
                denRes.push_back(denominator/2);
                denRes.push_back(denominator);
                break;
            }
        }
    }

    for(unsigned int i = 0; i < denRes.size(); i++){
        if(i == 0){
            res = res + "1/" + to_string(denRes[i]);
        }else{
            res = res + "+1/" + to_string(denRes[i]);
        }
    }

    return res;
}

int main()
{
    string str;
    while(cin >> str){
        string res = getResult(str);
        cout << res << endl;
    }
}
