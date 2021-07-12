/*
 * HJ89 24点运算
 * 计算24点是一种扑克牌益智游戏，随机抽出4张扑克牌，通过加(+)，减(-)，乘(*), 除(/)四种运算法则计算得到整数24，
 * 本问题中，扑克牌通过如下字符或者字符串表示，其中，小写joker表示小王，大写JOKER表示大王：
 * 3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER
 * 本程序要求实现：输入4张牌，输出一个算式，算式的结果为24点。
 * 详细说明：
 * 1.运算只考虑加减乘除运算，没有阶乘等特殊运算符号，没有括号，友情提醒，整数除法要当心，是属于整除，比如2/3=0，3/2=1；
 * 2.牌面2~10对应的权值为2~10, J、Q、K、A权值分别为为11、12、13、1；
 * 3.输入4张牌为字符串形式，以一个空格隔开，首尾无空格；如果输入的4张牌中包含大小王，则输出字符串“ERROR”，表示无法运算；
 * 4.输出的算式格式为4张牌通过 + - * /四个运算符相连，中间无空格，4张牌出现顺序任意，只要结果正确；
 * 5.输出算式的运算顺序从左至右，不包含括号，如1+2+3*4的结果为24，2 A 9 A不能变为(2+1)*(9-1)=24
 * 6.如果存在多种算式都能计算得出24，只需输出一种即可，如果无法得出24，则输出“NONE”表示无解。
 * 7.因为都是扑克牌，不存在单个牌为0的情况，且没有括号运算，除数(即分母)的数字不可能为0
 *
 * 输入描述：
 * 输入4张牌为字符串形式，以一个空格隔开，首尾无空格；
 * 输出描述：
 * 输出怎么运算得到24，如果无法得出24，则输出“NONE”表示无解，如果输入的4张牌中包含大小王，则输出字符串“ERROR”，表示无法运算；
 *
 * 示例1
 * 输入：
 * A A A A
 * 输出：
 * NONE
 * 说明：
 * 不能实现
 *
 * 示例2
 * 输入：
 * 4 2 K A
 * 输出：
 * K-A*4/2
 * 说明：
 * A+K*2-4也是一种答案，输出任意一种即可
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;


int compute(vector<int>& poke, vector<char>& track)
{
    int res = poke[0];
    for(int i = 0; i < 3; i++){
        if(track[i] == '+'){
            res = res + poke[i+1];
        }else if(track[i] == '-'){
            res = res - poke[i+1];
        }else if(track[i] == '*'){
            res = res * poke[i+1];
        }else{
            res = res / poke[i+1];
        }
    }
    return res;
}

string splice(vector<int>& poke, vector<char>& track)
{
    vector<string> index = {"0", "A", "2", "3", "4", "5", "6", "7", "8","9","10", "J", "Q", "K", "joker", "JOKER"};
    string res = index[poke[0]];
    for(int i = 0; i < 3; i++){
        res = res + track[i] + index[poke[i+1]];
    }
    return res;
}

string backtrack(vector<int>& poke, vector<char>& track)
{
    if(track.size() == 3){
        if(compute(poke, track) == 24){
            return splice(poke, track);
        }else{
            return "NONE";
        }
    }

    vector<char> temp = {'+', '-', '*', '/'};
    for(char c: temp){
        track.push_back(c);
        string res = backtrack(poke, track);
        if(res != "NONE") return res;
        track.pop_back();
    }

    return "NONE";
}


string getResult(string poke)
{

    vector<int> p;
    string temp;
    unsigned int i = 0, j = 0;
    while(j < poke.size()){
        if(poke[j] == ' '){
            temp = poke.substr(i, j-i);
            if(temp == "joker" || temp == "JOKER") return "ERROR";
            if(temp == "J"){
                p.push_back(11);
            }else if(temp == "Q"){
                p.push_back(12);
            }else if(temp == "K"){
                p.push_back(13);
            }else if(temp == "A"){
                p.push_back(1);
            }else{
                p.push_back(atoi(temp.c_str()));
            }
            i = j+1;
        }
        j++;
    }
    temp = poke.substr(i, j-i);
    if(temp == "joker" || temp == "JOKER") return "ERROR";
    if(temp == "J"){
        p.push_back(11);
    }else if(temp == "Q"){
        p.push_back(12);
    }else if(temp == "K"){
        p.push_back(13);
    }else if(temp == "A"){
        p.push_back(1);
    }else{
        p.push_back(atoi(temp.c_str()));
    }

    // p中的数字全排列
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(j == i) continue;
            for(int k = 0; k < 4; k++){
                if(k == i || k == j) continue;
                vector<int> p_ = {p[i], p[j], p[k], p[6-i-j-k]};
                vector<char> track;
                string res = backtrack(p_, track);
                if(res != "NONE") return res;
            }
        }
    }

    return "NONE";
}

int main()
{
    string poke;
    poke = "5 7 3 9";
    cout << getResult(poke) << endl;
//    while(getline(cin, poke)){
//        cout << getResult(poke) << endl;
//    }
}
































