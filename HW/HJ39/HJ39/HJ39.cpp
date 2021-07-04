// HJ39.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
判断两个IP是否属于同一子网
输入：
255.255.255.0
192.168.224.256
192.168.10.4
255.0.0.0
193.194.202.15
232.43.7.59
255.255.255.0
192.168.0.254
192.168.0.1
复制
输出：
1
2
0
复制
说明：
对于第一个例子:
255.255.255.0
192.168.224.256
192.168.10.4
其中IP:192.168.224.256不合法，输出1

对于第二个例子:
255.0.0.0
193.194.202.15
232.43.7.59
2个与运算之后，不在同一个子网，输出2

对于第三个例子，2个与运算之后，如题目描述所示，在同一个子网，输出0


*/
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

bool isSame(vector<int>& mask, vector<int>& ip1, vector<int>& ip2)
{
    int m1, m2;
    for (int i = 0; i < 4; i++)
    {
        m1 = mask[i] & ip1[i];
        m2 = mask[i] & ip2[i];
        if (m1 != m2) return false;
    }
    return true;
}



int main()
{
    string mask;
    string ip1, ip2;

    while (getline(cin, mask))
    {
        getline(cin, ip1);
        getline(cin, ip2);

        // 转换
        vector<int> IP1 = fun(ip1);
        vector<int> IP2 = fun(ip2);
        vector<int> Mask = fun(mask);

        // 判断子网掩码和ip是否合法
        // 先判断长度是否合法
        if (Mask.size() != 4 || IP1.size() != 4 || IP2.size() != 4) {
            cout << 1 << endl;
            continue;
        }

        // 判断掩码和IP是否合法
        if (!maskLegal(Mask) || !ipLegal(IP1) || !ipLegal(IP2)) {
            cout << 1 << endl;
            continue;
        }

        // 判断属不属于同一子网
        if (isSame(Mask, IP1, IP2))
        {
            cout << 0 << endl;
        }
        else {
            cout << 2 << endl;
        }
    }

}