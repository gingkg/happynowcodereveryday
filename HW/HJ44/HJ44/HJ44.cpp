// HJ44.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
问题描述：数独（Sudoku）是一款大众喜爱的数字逻辑游戏。玩家需要根据9X9盘面上的已知数字，推算出所有剩余空格的数字，
并且满足每一行、每一列、每一个3X3粗线宫内的数字均含1-9，并且不重复。

输入描述：
包含已知数字的9X9盘面数组[空缺位以数字0表示]

输出描述：
完整的9X9盘面数组
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<int> getNum(vector<vector<int>>& board, vector<int> track)
    {
        unordered_set<int> s = { 1,2,3,4,5,6,7,8,9 };
        vector<int> vec;
        // 行
        for (int i = 0; i < 9; i++) s.erase(board[track[0]][i]);
        // 列
        for (int i = 0; i < 9; i++) s.erase(board[i][track[1]]);
        // 3 * 3
        int a = track[0] / 3;
        int b = track[1] / 3;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                s.erase(board[a * 3 + i][b * 3 + j]);
            }
        }

        vec.assign(s.begin(), s.end());

        return vec;
    }

    bool dfs(vector<vector<int>>& board, vector<int> track)
    {
        if (track[0] == 9 && track[1] == 0) return true;

        cout << track[0] << " " << track[1] << endl;

        vector<int> next = { track[0], track[1] + 1 };
        if (next[1] >= 9) next = { next[0] + 1, 0 };

        if (board[track[0]][track[1]] == 0) {
            // 遍历所有可行数字
            vector<int> temp = getNum(board, track);
            for (int d : temp) {
                board[track[0]][track[1]] = d;
                if(dfs(board, next)) return true;
            }
            board[track[0]][track[1]] = 0;
        }
        else {
            return dfs(board, next);
        }

        return false;
    }


    vector<vector<int>> Sudoku(vector<vector<int>>& board)
    {
        dfs(board, { 0,0 });
        return board;
    }
};


int main()
{
    vector<vector<int>> board(9, vector<int>(9, 0));
    /*for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
        }
    }*/

    board = { {0,9,5,0,2,0,0,6,0},
            {0,0,7,1,0,3,9,0,2},
            {6,0,0,0,0,5,3,0,4},
            {0,4,0,0,1,0,6,0,7},
            {5,0,0,2,0,7,0,0,9},
            {7,0,3,0,9,0,0,2,0},
            {0,0,9,8,0,0,0,0,6},
            {8,0,6,3,0,2,1,0,5},
            {0,5,0,0,7,0,2,8,3} };

    Solution S;
    vector<vector<int>> res = S.Sudoku(board);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}


