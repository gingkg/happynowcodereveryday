// HJ50.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
描述
输入一个表达式（用字符串表示），求这个表达式的值。
保证字符串中的有效字符包括[‘0’-‘9’],‘+’,‘-’, ‘*’,‘/’ ,‘(’， ‘)’,‘[’, ‘]’,‘{’ ,‘}’。且表达式一定合法。



输入描述：
输入一个算术表达式

输出描述：
得到计算结果

示例1
输入：
3+2*{1+2*[-4/(8-6)+7]}
输出：
25

*/

#include <iostream>
#include <string>
#include <stack>
#include <cmath>
using namespace std;


class Solution
{
public:
    int getPriority(char c)
    {
        int priority = -1;  // -1代表错误
        if (c == '+' || c == '-')
            priority = 0;
        if (c == '*' || c == '/')
            priority = 1;
        return priority;
    }

    // 字符串转数字
    double string2float(string s) {
        double n = 0;
        bool isXiaoShu = false; // 判断当前的数字是不是小数部分
        int xiaoShuLength = 0;  // 记录小数部分的长度
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                n = n * 10 + (s[i] - '0');
                if (isXiaoShu)
                    xiaoShuLength++;
            }
            else if (s[i] == '.') {
                isXiaoShu = true; //开始进入小数部分
            }
        }
        return n * 1.0 / pow(10, xiaoShuLength);
    }
   

    string infix2postfix(string infix) {
        // 处理 {} []
        for (int i = 0; i < infix.size(); i++) {
            if (infix[i] == '{' || infix[i] == '[') {
                infix[i] = '(';
            }
            if (infix[i] == '}' || infix[i] == ']') {
                infix[i] = ')';
            }
        }

        // 处理负号
        int L = infix.size();
        int k = 0;
        while (k < L) {
            if (infix[k] == '-') {
                if (k == 0) {
                    infix = "(0" + infix;
                    k = k + 2;
                    for (k = k + 1; k < infix.size(); k++) {
                        if (!('0' <= infix[k] && infix[k] <= '9')) break;
                    }
                    infix = infix.substr(0, k) + ")" + infix.substr(k, infix.size() - k);
                    L = L + 3;
                }
                else if (infix[k-1] == '(') {
                    infix = infix.substr(0, k) + "(0" + infix.substr(k, infix.size()-k);
                    k = k + 2;
                    for (k = k + 1; k < infix.size(); k++) {
                        if (!('0' <= infix[k] && infix[k] <= '9')) break;
                    }
                    infix = infix.substr(0, k) + ")" + infix.substr(k, infix.size() - k);
                    L = L + 3;
                }
            }
            k++;
        }

        string postfix;   // 后缀表达式
        stack<char> op;     // 保存中间结果
        for (int i = 0; i < infix.length(); i++) {
            if (infix[i] >= '0' && infix[i] <= '9') {
                // 数字直接进入结果表示
                string tempNumStr;
                while (i < infix.length() && (infix[i] >= '0' && infix[i] <= '9' || infix[i] == '.')) {
                    tempNumStr += infix[i];
                    i++;
                }
                //  double num = string2float(tempNumStr); 暂时不需要转换, 加入后缀表达式即可
                postfix += tempNumStr;
                postfix += " ";
            }
            if (op.empty() || op.top() == '(' || infix[i] == '(') {
                // 中间结构栈为空,栈顶是左括号,遇到左括号，则运算符直接入栈
                op.push(infix[i]);
            }
            else if (infix[i] == ')') {
                // 遇到左括号则一直取出中间结果栈的元素加到后缀表达式中
                while (!op.empty()) {
                    char temp = op.top();
                    op.pop();
                    if (temp == '(') {
                        break;
                    }
                    postfix += temp;
                    postfix += " ";
                }
            }
            else if (getPriority(infix[i]) > getPriority(op.top())) {
                op.push(infix[i]);
            }
            else { // getPriority(infix[i]) < getPriority(op.top())
                char temp = op.top();
                op.pop();
                postfix += temp;
                postfix += " ";
                // 重新用当前的运算符继续判断
                i--;
            }
        }
        while (!op.empty()) {
            char temp = op.top();
            op.pop();
            postfix += temp;
            postfix += " ";
        }
        return postfix;
    }

    double postfix2result(string postfix) {
        stack<double> numSt;
        double n1, n2;
        for (int i = 0; i < postfix.length(); i++) {
            if (postfix[i] == ' ')   // 处理一下空格
                continue;
            if (postfix[i] >= '0' && postfix[i] <= '9') {
                // 数字直接进入结果表示
                string tempNumStr;
                while (i < postfix.length() && (postfix[i] >= '0' && postfix[i] <= '9' || postfix[i] == '.')) {
                    if (postfix[i] == ' ') {
                        i++;    //处理一下空格
                        continue;
                    }
                    tempNumStr += postfix[i];
                    i++;
                }
                double num = string2float(tempNumStr);
                numSt.push(num);
            }
            else {
                n2 = numSt.top();
                numSt.pop();
                n1 = numSt.top();
                numSt.pop();
                if (postfix[i] == '+')
                    n1 = n1 + n2;
                else if (postfix[i] == '-')
                    n1 = n1 - n2;
                else if (postfix[i] == '*')
                    n1 = n1 * n2;
                else if (postfix[i] == '/') {
                    if (n2 > -0.00001 && n2 < 0.00001) {
                        cout << "Error! divided by zero!" << endl;
                        exit(EXIT_FAILURE);
                    }
                    n1 = n1 / n2;
                }
                else {
                    cout << "undefined operation " << postfix[i] << " occur!" << endl;
                    exit(EXIT_FAILURE);
                }
                numSt.push(n1);
            }
        }
        double result = numSt.top();
        numSt.pop();
        return result;
    }

    double compute(string infixStr)
    {
        string postfixStr = infix2postfix(infixStr);
        double result = postfix2result(postfixStr);
        return result;
    }
};




int main()
{
    Solution S;

    string str = "3+2*{1+2*[-4/(8-6)+7]}";
    cout << S.compute(str) << endl;


    /*while (getline(cin, str))
    {
        cout << compute(str) << endl;
    }*/
}


