// HJ19.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Log
{
private:
    unordered_map<string, int> index;
    vector<string> data;
    int size = 0;
    int capacity = 8;

public:
    Log() {

    };

public:
    string name(string& str)
    {
        int L = str.size();
        int i = L - 1, j = L - 1;
        int n = 0;
        bool flag = false;
        while (j >= 0) {
            if (str[j] == '\\' || n >= 16) {
                return str.substr(j+1, i - j);
            }
            if (flag) n++;
            if (str[j] == ' ') {
                flag = true;
            }
            j--;
        }
        return str;
    }

    void input(string& str)
    {
        string file = name(str);

        if (!index.count(file)) {
            if (size == capacity) {
                data.erase(data.begin());
                data.push_back(file);
            }
            else {
                data.push_back(file);
                size++;
            }
        }

        index[file]++;
    }

    void print()
    {
        for (string d : data)
        {
            cout << d << " " << index[d] << endl;
        }
    }
};


int main()
{
    Log log;
    string str;

    vector<string> raw = {
        "G:\\rp\\onajqj\\maahmq 631",
        "E:\\njfgjkcrh 641",
        "C:\\co\\zk\\ao\\bxgxjfgrwckfxekeqro 629",
        "D:\\mf\\si\\jmfdahkeffyjjsf 646",
        "E:\\wn\\arefkiz 633",
        "C:\\gpjleb\\cinhhx\\zjydgr\\njfgjkcrh 640",
        "E:\\nwrrhx\\qyw\\bxgxjfgrwckfxekeqro 636",
        "G:\\usgsl\\ywr\\tve\\cqekvaxypemktyurn 647",
        "C:\\jftbig\\arefkiz 650",
        "F:\\rgk\\cai\\arefkiz 640",
        "D:\\tvse\\vs\\dhzrmy\\njfgjkcrh 634",
        "E:\\coba\\qbs\\xagq\\njfgjkcrh 628",
        "F:\\wnfsmf\\oxrvbv\\njfgjkcrh 632",
        "C:\\khqx\\nv\\jmfdahkeffyjjsf 637",
        "F:\\hm\\ra\\uaxckn\\bxgxjfgrwckfxekeqro 647",
        "D:\\soq\\jmfdahkeffyjjsf 642",
        "F:\\moxnw\\szxcdhlaytgj 639",
        "E:\\avcop\\jd\\vwtrt\\njfgjkcrh 650",
        "E:\\hou\\vv\\szxcdhlaytgj 631",
        "C:\\uozkwd\\bxgxjfgrwckfxekeqro 650",
        "F:\\jmfdahkeffyjjsf 650",
        "E:\\hgoxms\\nwax\\szxcdhlaytgj 633",
        "F:\\vylww\\zhh\\cqekvaxypemktyurn 643",
        "C:\\njfgjkcrh 637",
        "F:\\bfn\\dxwjje\\jmfdahkeffyjjsf 632",
        "E:\\bxgxjfgrwckfxekeqro 634",
        "G:\\gwuusj\\ized\\qq\\szxcdhlaytgj 646",
        "F:\\arefkiz 644",
        "G:\\zsw\\uewu\\arefkiz 634",
        "E:\\ja\\zg\\njfgjkcrh 644",
        "D:\\gfute\\ju\\wuy\\szxcdhlaytgj 636",
        "C:\\mpgcx\\kcgi\\arefkiz 645",
        "C:\\zayn\\jmfdahkeffyjjsf 648",
        "F:\\kkplu\\avvw\\hbzmwj\\jmfdahkeffyjjsf 648",
        "E:\\maahmq 631",
        "E:\\hs\\xnto\\jmfdahkeffyjjsf 645",
        "G:\\cqekvaxypemktyurn 633",
        "D:\\maahmq 646",
        "E:\\jmfdahkeffyjjsf 636",
        "G:\\hbvm\\szxcdhlaytgj 642"
    };

    for (string r : raw) {
        log.input(r);
    }


    /*while (getline(cin, str)) {
        log.input(str);
    }*/
    log.print();
}
