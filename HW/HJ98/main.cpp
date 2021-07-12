/*HJ98 自动售货系统*/

#include <iostream>
#include <string>
#include <vector>
#include "vendingsystem.h"
using namespace std;

int main()
{
    string str;
    vector<string> cmds;
    VendingSystem sys;

    str = "r 22-18-21-21-7-20 3-23-10-6;c;q0;p 1;b A6;c;b A5;b A1;c;q1;p 5;r 28-12-11-1-16-10 19-30-8-11;b A1;p 1;";
//    getline(cin, str);
    int i = 0, j = 0;
    while(j < int(str.size())){
        if(str[j] == ';'){
            cmds.push_back(str.substr(i, j-i));
            i = j + 1;
        }
        j++;
    }
    for(unsigned int i = 0; i < cmds.size(); i++){
        //cout << cmds[i] << endl;
        sys.Run(cmds[i]);
    }
}
