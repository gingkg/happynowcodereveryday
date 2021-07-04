// HJ18.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> fun(string str)
{
    vector<int> res;
    int i = 0, j = 0;
    while (j < str.size())
    {
        if (str[j] == '.' && i < j)
        {
            res.push_back(atoi(str.substr(i, j - i).c_str()));
            i = j + 1;
        }
        j++;
    }
    if (i < j) res.push_back(atoi(str.substr(i, j - i).c_str()));
    return res;
}


bool maskLegal(vector<int>& mask)
{
    // 保证mask.size() = 4
    // 全0，全1非法
    if ((mask[0] == 255 && mask[1] == 255 && mask[2] == 255 && mask[3] == 255)
        || mask[0] == 0 && mask[1] == 0 && mask[2] == 0 && mask[3] == 0) {
        return false;
    }
    if (0 <= mask[0] && mask[0] < 256 && 0 <= mask[1] && mask[1] < 256
        && 0 <= mask[2] && mask[2] < 256 && 0 <= mask[3] && mask[3] < 256)
    {
        int pos = 0;
        int i = 0;
        for (int m : mask)
        {
            int index = 128;
            while (index > 0)
            {
                i++;
                if ((m & index) == index)
                {
                    if (i - pos > 1) return false;
                    pos = i;
                }
                index = (index >> 1);
            }
        }
        return true;
    }
    else {
        return false;
    }
}

bool ipLegal(vector<int>& IP)
{
    // 保证IP.size() = 4
    if (0 <= IP[0] && IP[0] < 256 && 0 <= IP[1] && IP[1] < 256
        && 0 <= IP[2] && IP[2] < 256 && 0 <= IP[3] && IP[3] < 256)
    {
        return true;
    }
    else {
        return false;
    }
}

int ipClassify(vector<int>& IP)
{
    if (1 <= IP[0] && IP[0] <= 126) return 0;
    if (128 <= IP[0] && IP[0] <= 191) return 1;
    if (192 <= IP[0] && IP[0] <= 223) return 2;
    if (224 <= IP[0] && IP[0] <= 239) return 3;
    if (240 <= IP[0] && IP[0] <= 255) return 4;
    return -1;
}

bool ipPrivate(vector<int>& IP)
{
    if (IP[0] == 10
        || (IP[0] == 172 && 16 <= IP[1] && IP[1] <= 31)
        || (IP[0] == 192 && IP[1] == 168))
    {
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    string str;
    vector<string> raw;
    while (getline(cin, str))
    {
        raw.push_back(str);
    }

    vector<int> count(7, 0);

    for (string s : raw)
    {
        // 分离ip和子网掩码， 并转换为int
        vector<int> IP = fun(s.substr(0, s.find("~")));
        vector<int> mask = fun(s.substr(s.find("~") + 1, s.size() - (s.find("~") + 1)));
        // 先判断长度是否合法
        if (mask.size() != 4 || IP.size() != 4) {
            count[5]++;
            continue;
        }
        // 判断掩码是否合法
        if (!maskLegal(mask)) {
            count[5]++;
            continue;
        }
        // 判断IP是否合法
        if (!ipLegal(IP)) {
            count[5]++;
            continue;
        }
        // 跳过两类本地ip
        if (IP[0] == 0 || IP[0] == 127) continue;
        // IP分类
        count[ipClassify(IP)]++;
        // 是否为私有ip
        if (ipPrivate(IP)) {
            count[6]++;
        }
    }

    for (int i = 0; i < count.size() - 1; i++)
    {
        cout << count[i] << " ";
    }
    cout << count[count.size() - 1] << endl;

}
