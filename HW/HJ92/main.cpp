/*J92 在字符串中找出连续最长的数字串
输入一个字符串，返回其最长的数字子串，以及其长度。若有多个最长的数字子串，则将它们全部输出（按原字符串的相对位置）
本题含有多组样例输入。

输入描述：
输入一个字符串。

输出描述：
输出字符串中最长的数字字符串和它的长度，中间用逗号间隔。如果有相同长度的串，则要一块儿输出（中间不要输出空格）。

示例1
输入：
abcd12345ed125ss123058789
a8a72a6a5yy98y65ee1r2
复制
输出：
123058789,9
729865,2
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> getResult(string& str)
{
    vector<string> res;
    unsigned int length = 0;
    int i = 0, j = 0;
    while(j < int(str.size())){
        if(!('0' <= str[j] && str[j] <= '9')){
            if(j > i){
                string temp = str.substr(i, j-i);
                if(temp.size() == length){
                    res.push_back(temp);
                }
                if(temp.size() > length){
                    res.clear();
                    res.push_back(temp);
                    length = temp.size();
                }
                i = j + 1;
            }
        }
        if(!('0' <= str[i] && str[i] <= '9')){
            i++;
        }
        j++;
    }
    if(j > i){
        string temp = str.substr(i, j-1);
        if(temp.size() == length){
            res.push_back(temp);
        }
        if(temp.size() > length){
            res.clear();
            res.push_back(temp);
            length = temp.size();
        }
    }

    return res;
}

int main()
{
    string str;

    str = "a8a72a6a5yy98y65ee1r2";
    vector<string> res = getResult(str);
    for(auto s:res){
        cout << s;
    }
    if(res.size() > 0) cout << "," <<res[0].size() << endl;


//    while(getline(cin, str))
//    {
//        vector<string> res = getResult(str);
//        for(auto s:res){
//            cout << s << ",";
//        }
//        cout << res.size() << endl;
//    }
}
