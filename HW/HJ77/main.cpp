/*
 * HJ77  火车进站

 * 描述
给定一个正整数N代表火车数量，0<N<10，接下来输入火车入站的序列，一共N辆火车，每辆火车以数字1-9编号，火车站只有一个方向进出，同时停靠在火车站的列车中，只有后进站的出站了，先进站的才能出站。
要求输出所有火车出站的方案，以字典序排序输出。
输入描述：
有多组测试用例，每一组第一行输入一个正整数N（0

输出描述：
输出以字典序从小到大排序的火车出站序列号，每个编号以空格隔开，每个输出序列换行，具体见sample。

示例1
输入：
3
1 2 3
输出：
1 2 3
1 3 2
2 1 3
2 3 1
3 2 1
说明：
第一种方案：1进、1出、2进、2出、3进、3出
第二种方案：1进、1出、2进、3进、3出、2出
第三种方案：1进、2进、2出、1出、3进、3出
第四种方案：1进、2进、2出、3进、3出、1出
第五种方案：1进、2进、3进、3出、2出、1出
请注意，[3,1,2]这个序列是不可能实现的。
*/


#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <set>
using namespace std;


void backtrack(set<vector<int>>& res, stack<int> &s1, stack<int> &s2, vector<int> track)
{
    if(s1.empty() && s2.empty()){
        res.emplace(track);
        return;
    }

    // 选择，要么进站，要么出站
    if(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
        backtrack(res, s1, s2, track);
        // 复原
        s1.push(s2.top());
        s2.pop();
    }

    if(!s2.empty()){
        int temp = s2.top();
        track.push_back(temp);
        s2.pop();
        backtrack(res, s1, s2, track);
        s2.push(temp);
    }

    return;
}

set<vector<int>> getResult(vector<int>& vec)
{
    stack<int> s1, s2;
    set<vector<int>> res;
    for(int i = vec.size()-1; i >=0; i--){
        s1.push(vec[i]);
    }

    backtrack(res, s1, s2, {});

    return res;
}

int main()
{
    int N;
    vector<int> vec = {1,2,3};
    set<vector<int>> res = getResult(vec);

    cout << "-----------------------------" << endl;
    for(auto iter = res.begin(); iter != res.end(); iter++){
        for(int i = 0; i < (*iter).size(); i++){
            cout << (*iter)[i] << " ";
        }
        cout << endl;
    }


//    while(cin >> N){
//        vector<int> vec(N, 0);
//        for(int i=0; i < N; i++){
//            cin >> vec[i];
//        }
//        vector<vector<int>> res = getResult(vec);
//        for(unsigned int i = 0; i < res.size(); i++){
//            for(unsigned int j = 0; j < res[i].size(); j++){
//                cout << res[i][j] << " ";
//            }
//            cout << endl;
//        }
//    }
}
















