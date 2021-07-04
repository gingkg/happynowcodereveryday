// HJ43.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
迷宫问题

描述
定义一个二维数组N*M（其中2<=N<=10;2<=M<=10），如5 × 5数组下所示：


int maze[5][5] = {
0, 1, 0, 0, 0,
0, 1, 1, 1, 0,
0, 0, 0, 0, 0,
0, 1, 1, 1, 0,
0, 0, 0, 1, 0,
};


它表示一个迷宫，其中的1表示墙壁，0表示可以走的路，只能横着走或竖着走，不能斜着走，要求编程序找出从左上角到右下角的最短路线。入口点为[0,0],既第一格是可以走的路。


本题含有多组数据。

输入描述：
输入两个整数，分别表示二维数组的行数，列数。再输入相应的数组，其中的1表示墙壁，0表示可以走的路。数据保证有唯一解,不考虑有多解的情况，即迷宫只有一条通道。

输出描述：
左上角到右下角的最短路径，格式如样例所示。

示例1:

输入：
5 5
0 1 0 0 0
0 1 1 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
输出：
(0,0)
(1,0)
(2,0)
(2,1)
(2,2)
(2,3)
(2,4)
(3,4)
(4,4)


示例2:
输入：
5 5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 1
0 1 1 1 0
0 0 0 0 0
输出：
(0,0)
(1,0)
(2,0)
(3,0)
(4,0)
(4,1)
(4,2)
(4,3)
(4,4)

说明：
注意：不能斜着走！！
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    bool dfs(vector<vector<int>>& maze, vector<int> track, vector<vector<int>>& res, vector<vector<bool>>& flag)
    {
        int N = maze.size();
        int M = maze[0].size();
        vector<vector<int>> direction = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

        if (track[0] == N - 1 && track[1] == M - 1) {
            return true;
        }

        for (auto&& d : direction)
        {
            vector<int> temp = { track[0] + d[0], track[1] + d[1] };
            if (0 <= temp[0] && temp[0] < N && 0 <= temp[1] && temp[1] < M
                && maze[temp[0]][temp[1]] == 0
                && (!flag[temp[0]][temp[1]]))
            {
                flag[temp[0]][temp[1]] = true;
                if (dfs(maze, temp, res, flag))
                {
                    res.push_back(temp);
                    return true;
                }
                flag[temp[0]][temp[1]] = false;
            }
        }

        return false;
    }

    vector<vector<int>> explorer(vector<vector<int>>& maze)
    {
        int N = maze.size();
        int M = maze[0].size();

        vector<vector<int>> res;
        vector<vector<bool>> flag(N, vector<bool>(M, false));

        // 深度优先搜索
        dfs(maze, { 0,0 }, res, flag);

        res.push_back({ 0,0 });

        return res;

    }
};



int main()
{
    Solution S;
    int N, M;
    while (cin >> N, cin >> M)
    {
        vector<vector<int>> maze(N, vector<int>(M, 0));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> maze[i][j];
            }
        }

        vector<vector<int>> res = S.explorer(maze);

        for (int i = res.size() - 1; i >= 0; i--)
        {
            cout << "(" << res[i][0] << "," << res[i][1] << ")" << endl;
        }
    }
}


