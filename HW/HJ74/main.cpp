#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> getResult(string& str)
{
    vector<string> res;
    int i = 0, j = 0;
    bool flag = false;
    while(j < int(str.size())){
        if(!flag && str[j] == ' '){
            if(j > i){
                res.push_back(str.substr(i, j-i));
            }
            i = j + 1;
        }
        if(str[j] == '"'){
            if(!flag){
                flag = true;
            }else{
                res.push_back(str.substr(i, j-i));
                flag = false;
            }
            i = j + 1;
        }
        j++;
    }

    if(i != j){
        res.push_back(str.substr(i, j-i));
    }
    return res;
}

int main()
{
    string str;

    str = "xcopy /s \"C:\\program files\" \"d:\\\"";
    vector<string> res = getResult(str);
    cout << res.size() << endl;
    for(auto iter = res.begin(); iter != res.end(); iter++){
        cout << *iter << endl;
    }

//    while(getline(cin, str)){
//        vector<string> res = getResult(str);
//        cout << res.size() << endl;
//        for(auto iter = res.begin(); iter != res.end(); iter++){
//            cout << *iter << endl;
//        }
//    }
}
