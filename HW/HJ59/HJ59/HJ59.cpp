// HJ59.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
using namespace std;

string fun(string& str)
{
    unordered_map<char, int> index;
    stringstream stream;

    for (char c : str) {
        index[c]++;
    }

    for (char c : str) {
        if (index[c] == 1) {
            stream << c;
            return stream.str();
        }
    }

    return "-1";
}


int main()
{
    string str;
    str = "asdfasdfo";
    cout << fun(str) << endl;
    /*while (getline(cin, str)) {
        cout << fun(str) << endl;
    }*/
}