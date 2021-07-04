// HJ16.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;


int solution(vector<vector<int>>& data, int N)
{
    N = N / 10;
    vector<vector<int>> v, v_;
    vector<vector<int>> p, p_;
    for (vector<int> d : data) {
        if (d[2] == 0) {
            // 主件
            v.push_back({ d[0]/10, 0, 0 });
            p.push_back({ d[1], 0, 0 });
        }
        else {
            v.push_back({});
            p.push_back({});
        }
    }
    for (vector<int> d : data) {
        if (d[2] > 0) {
            if (v[d[2] - 1][1] == 0) {
                v[d[2] - 1][1] = d[0]/10;
                p[d[2] - 1][1] = d[1];
            }
            else {
                v[d[2] - 1][2] = d[0]/10;
                p[d[2] - 1][2] = d[1];
            }
        }
    }
    for (int i = 0; i < v.size(); i++) {
        if (!v[i].empty()) {
            v_.push_back(v[i]);
            p_.push_back(p[i]);
        }
    }

    v = v_;
    p = p_;

    for (int i = 0; i < v.size(); i++) {
        cout << v[i][0] << " " << v[i][1] << " " << v[i][2] << endl;
    }
    cout << "-----------------------" << endl;
    for (int i = 0; i < p.size(); i++) {
        cout << p[i][0] << " " << p[i][1] << " " << p[i][2] << endl;
    }

    int m = v.size();
    vector<vector<int>> dp(m + 1, vector<int>(N + 1, 0));

    for (int i = 1; i < m + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            vector<int> a(5, 0);
            a[0] = dp[i - 1][j];
            if (j >= v[i - 1][0]) {
                a[1] = dp[i - 1][j - v[i - 1][0]] + v[i-1][0]*p[i-1][0];
            }
            if (j >= (v[i - 1][0] + v[i - 1][1])) {
                a[2] = dp[i - 1][j - v[i - 1][0] - v[i - 1][1]] + v[i - 1][0] * p[i - 1][0] + v[i - 1][1] * p[i - 1][1];
            }
            if (j >= (v[i - 1][0] + v[i - 1][2])) {
                a[3] = dp[i - 1][j - v[i - 1][0] - v[i - 1][2]] + v[i - 1][0] * p[i - 1][0] + v[i - 1][2] * p[i - 1][2];
            }
            if (j >= (v[i - 1][0] + v[i - 1][1] + v[i - 1][2])) {
                a[4] = dp[i - 1][j - v[i - 1][0] - v[i - 1][1] - v[i - 1][2]] + v[i - 1][0] * p[i - 1][0] + 
                    v[i - 1][1] * p[i - 1][1] + v[i - 1][2] * p[i - 1][2];
            }
            dp[i][j] = *max_element(a.begin(), a.end());
        }
    }

    return dp[m][N]*10;
}


int main()
{
    int N, m;
    cin >> N >> m;
    // 我为何如此愚蠢？？？？？？？

    vector<vector<int>> data(m, vector<int>(3, 0));
    for (int i = 0; i < m; i++)
    {
        cin >> data[i][0] >> data[i][1] >> data[i][2];
    }

    cout << solution(data, N) << endl;
}