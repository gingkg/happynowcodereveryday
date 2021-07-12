/*HJ91 走方格的方案数
 * 请计算n*m的棋盘格子（n为横向的格子数，m为竖向的格子数）沿着各自边缘线从左上角走到右下角，总共有多少种走法，要求不能走回头路，即：只能往右和往下走，不能往左和往上走。

本题含有多组样例输入。
输入描述：
每组样例输入两个正整数n和m，用空格隔开。(1≤n,m≤8)

输出描述：
每组样例输出一行结果

示例1
输入：
2 2
1 2

输出：
6
3
*/

#include <iostream>
using namespace std;

void dfs(int n, int m, int& res, int i, int j)
{
    if(n-1 == i && m-1 == j){
        res++;
        return;
    }
    // 向右走
    if(i+1<n){
        dfs(n,m,res,i+1,j);
    }
    // 向下走
    if(j+1<m){
        dfs(n,m,res,i,j+1);
    }
    return;
}

int getResult(int n, int m)
{
    int res = 0;
    dfs(n+1, m+1, res,0,0);
    return res;
}

int main()
{
    int n, m;
    while(cin >> n >> m){
        cout << getResult(n,m) << endl;
    }
}
