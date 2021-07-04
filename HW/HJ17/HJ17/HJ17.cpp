// HJ17.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void fun(string& str, vector<char>& dire, vector<int>& dist)
{
    int i = 0, j = 0;
    while (j < str.size())
    {
        if (str[j] == ';') {
            string curStr = str.substr(i, j - i);
            if (!curStr.empty() && (curStr[0] == 'A' || curStr[0] == 'S' || curStr[0] == 'D' || curStr[0] == 'W'))
            {
                if (curStr.size() == 2 && 48 <= curStr[1] && curStr[1] <= 57) {
                    dire.push_back(curStr[0]);
                    dist.push_back(curStr[1] - '0');
                }
                if (curStr.size() == 3 && 48 <= curStr[1] && curStr[1] <= 57 && 48 <= curStr[2] && curStr[2] <= 57) {
                    dire.push_back(curStr[0]);
                    dist.push_back((curStr[1] - '0') * 10 + (curStr[2] - '0'));
                }
            }
            i = j + 1;
        }
        j++;
    }
}

vector<int> result(vector<int>& start, vector<char>& dire, vector<int>& dist)
{
    vector<int> end = start;
    for (int i = 0; i < dire.size(); i++)
    {
        switch (dire[i])
        {
        case 'A':
            end[0] = end[0] - dist[i];
            break;
        case 'D':
            end[0] = end[0] + dist[i];
            break;
        case 'W':
            end[1] = end[1] + dist[i];
            break;
        case 'S':
            end[1] = end[1] - dist[i];
            break;
        }
    }
    return end;
}


int main()
{
    string str;
    while (getline(cin, str))
    {
        // 将字符串处理成合法vector
        vector<char> dire;
        vector<int> dist;
        fun(str, dire, dist);

        vector<int> start = { 0,0 };
        vector<int> end = result(start, dire, dist);

        cout << end[0] << "," << end[1] << endl;
    }
}