// HJ42.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string num2eng100(int n)
    {
        string res = "";

        // if (n == 0) return res;

        vector<string> datain20 = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
            "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty" };
        vector<string> datain100 = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

        if (n <= 20) {
            res = res + datain20[n];
        }
        else if(20 < n && n < 100) {
            if (n % 10 == 0)
            {
                res = res + datain100[n / 10 - 2];
            }
            else {
                res = res + datain100[n / 10 - 2] + " " + datain20[n % 10];
            }
        }
        else {
            res = res + datain20[n / 100] + " hundred";
            if (0 < n % 100 && n % 100 <= 20) res = res + " and " + datain20[(n % 100) % 100];
            if (20 < n % 100 && n % 100 < 100)
            {
                if ((n % 100) % 10 == 0)
                {
                    res = res + " and " + datain100[(n % 100) / 10 - 2];
                }
                else {
                    res = res + " and " + datain100[(n % 100) / 10 - 2] + " " + datain20[(n % 100) % 10];
                }
            }
               
        }
        return res;
    }


    string num2english(long n)
    {
        string res = "";
        if (n == 0) return "zero";

        vector<string> unit = { "billion", "million","thousand" };

        // 3个3个分割
        vector<int> raw;
        while (n > 0) {
            raw.push_back(n % 1000);
            n = n / 1000;
        }

        if (raw.size() == 1)
        {
            res = res + num2eng100(raw[0]);
        }
        if (raw.size() == 2)
        {
            res = res + num2eng100(raw[1]) + " thousand " + num2eng100(raw[0]);
        }
        if (raw.size() == 3)
        {
            if (num2eng100(raw[1]) == "")
            {
                res = res + num2eng100(raw[2]) + " million " + num2eng100(raw[0]);
            }
            else {
                res = res + num2eng100(raw[2]) + " million " + num2eng100(raw[1]) + " thousand " + num2eng100(raw[0]);
            }
        }

        return res;
    }
};


int main()
{
    long n;
    Solution S;
    while (cin >> n)
    {
        cout << S.num2english(n) << endl;
    }
}

