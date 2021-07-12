/* HJ93 数组分组
输入int型数组，询问该数组能否分成两组，使得两组中各元素加起来的和相等，并且，所有5的倍数必须在其中一个组中，
所有3的倍数在另一个组中（不包括5的倍数），能满足以上条件，输出true；不满足时输出false。

本题含有多组样例输入。
输入描述：
第一行是数据个数，第二行是输入的数据
输出描述：
返回true或者false

示例1
输入：
4
1 5 -5 1
3
3 5 8
复制
输出：
true
false
复制
说明：
第一个样例：
第一组：5 -5 1
第二组：1
第二个样例：由于3和5不能放在同一组，所以不存在一种分法。
*/


#include <iostream>
#include <vector>
#include <numeric>
using namespace std;


bool backtrack(vector<int>& vec, int i, int current, int& target)
{
    if(current == target) return true;
    if(i >= int(vec.size())) return false;
    //要
    if(backtrack(vec, i+1, current+vec[i], target)){
        return true;
    }
    // 不要
    if(backtrack(vec, i+1, current, target)){
        return true;
    }
    return false;
}


bool getReault(vector<int>& vec)
{
    int sum = accumulate(vec.begin(), vec.end(), 0);
    if(sum % 2 != 0) return false;
    int x = 0;
    vector<int> rest;
    for(int i: vec){
        if(i % 5 == 0){
            x += i;
        }else if(i % 3 == 0){
            continue;
        }else{
            rest.push_back(i);
        }
    }

    int target = (sum - 2 * x) / 2;
    int current = 0;

    if(backtrack(rest, 0, current, target)){
        return true;
    }else{
        return false;
    }
}

int main()
{
    vector<int> vec = {3, 8, 8, 5, 14};
    if(getReault(vec)){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }

//    int N;
//    while(cin >> N){
//        vector<int> vec(N);
//        for(int i = 0; i < N; i++){
//            cin >> vec[i];
//        }
//        if(getReault(vec)){
//            cout << "true" << endl;
//        }else{
//            cout << "false" << endl;
//        }
//    }
}



























