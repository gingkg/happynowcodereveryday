#include <iostream>
#include <string>
#include <vector>
using namespace std;

int getResult(string& s1, string& s2)
{
    int res = 0;
    int m = s1.size(), n = s2.size();
    vector<vector<int>> mat(m+1, vector<int>(n+1, 0));
    for(int i = 1; i < m+1; i++){
        for(int j = 1; j < n+1; j++){
            if(s1[i-1] == s2[j-1]){
                mat[i][j] = mat[i-1][j-1] + 1;
                if(mat[i][j] > res){
                    res = mat[i][j];
                }
            }
        }
    }
    return res;
}


int main()
{
    string s1, s2;
    s1 = "asdfas";
    s2 = "werasdfaswer";
    cout << getResult(s1, s2) << endl;
//    while(cin >> s1 >> s2){
//        cout << getResult(s1, s2) << endl;
//    }
}
