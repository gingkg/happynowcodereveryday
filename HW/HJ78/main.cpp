/*
 * HJ80 整型数组合并
将两个整型数组按照升序合并，并且过滤掉重复数组元素。
输出时相邻两数之间没有空格。
请注意本题有多组样例。

输入描述：
输入说明，按下列顺序输入：
1 输入第一个数组的个数
2 输入第一个数组的数值
3 输入第二个数组的个数
4 输入第二个数组的数值

输出描述：
输出合并之后的数组

示例1
输入：
3
1 2 5
4
-1 0 3 2
输出：
-101235
*/

#include <iostream>
#include <set>
#include <vector>
using namespace std;

set<int> getResult(vector<int>& v1, vector<int>& v2)
{
    set<int> s;
    for(int i : v1){
        s.emplace(i);
    }
    for(int i : v2){
        s.emplace(i);
    }
    return s;
}

int main()
{
    int m, n;
    while(cin >> m){
        vector<int> v1(m, 0);
        for(int i = 0; i < m; i++){
            cin >> v1[i];
        }
        cin >> n;
        vector<int> v2(n, 0);
        for(int i = 0; i < n; i++){
            cin >> v2[i];
        }
        set<int> res = getResult(v1, v2);
        for(auto iter = res.begin(); iter != res.end(); iter++){
            cout << *iter;
        }
        cout << endl;
    }


}
