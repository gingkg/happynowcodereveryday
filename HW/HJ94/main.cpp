/* HJ94 记票统计
请实现一个计票统计系统。你会收到很多投票，其中有合法的也有不合法的，请统计每个候选人得票的数量以及不合法的票数。
本题有多组样例输入。

输入描述：
输入候选人的人数n，第二行输入n个候选人的名字（均为大写字母的字符串），第三行输入投票人的人数，第四行输入投票。

输出描述：
按照输入的顺序，每行输出候选人的名字和得票数量，最后一行输出不合法的票数。

示例1
输入：
4
A B C D
8
A D E CF A GG A B
复制
输出：
A : 3
B : 1
C : 0
D : 1
Invalid : 3
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


unordered_map<string, int> getResult(vector<string>& candidates, vector<string>& votations)
{
    unordered_map<string, int> res;

    for(string s: candidates){
        res[s] = 0;
    }
    res["Invalid"] = 0;

    for(string s: votations){
        if(count(candidates.begin(), candidates.end(), s)){
            res[s]++;
        }else{
            res["Invalid"]++;
        }
    }

    return res;
}

int main()
{
    int n1, n2;
    while(cin >> n1){
        vector<string> candidates(n1);
        for(int i = 0; i < n1; i++){
            cin >> candidates[i];
        }
        cin >> n2;
        vector<string> votations(n2);
        for(int i = 0; i < n2; i++){
            cin >> votations[i];
        }
        unordered_map<string, int> res = getResult(candidates, votations);
        for(string s: candidates){
            cout << s << " : " << res[s] << endl;
        }
        cout << "Invalid" << " : " << res["Invalid"] << endl;
    }
}



















