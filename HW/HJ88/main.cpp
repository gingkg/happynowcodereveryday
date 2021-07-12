/*
 * HJ88 扑克牌大小
 * 扑克牌游戏大家应该都比较熟悉了，一副牌由54张组成，含3~A、2各4张，小王1张，大王1张。
 * 牌面从小到大用如下字符和字符串表示（其中，小写joker表示小王，大写JOKER表示大王）：
 * 3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER
 * 输入两手牌，两手牌之间用"-"连接，每手牌的每张牌以空格分隔，"-"两边没有空格，如：4 4 4 4-joker JOKER。
 * 请比较两手牌大小，输出较大的牌，如果不存在比较关系则输出ERROR。
 * 基本规则：
 * （1）输入每手牌可能是个子、对子、顺子（连续5张）、三个、炸弹（四个）和对王中的一种，不存在其他情况，由输入保证两手牌都是合法的，顺子已经从小到大排列；
 * （2）除了炸弹和对王可以和所有牌比较之外，其他类型的牌只能跟相同类型的存在比较关系（如，对子跟对子比较，三个跟三个比较），不考虑拆牌情况（如：将对子拆分成个子）；
 * （3）大小规则跟大家平时了解的常见规则相同，个子、对子、三个比较牌面大小；顺子比较最小牌大小；炸弹大于前面所有的牌，炸弹之间比较牌面大小；对王是最大的牌；
 * （4）输入的两手牌不会出现相等的情况。
 *
 * 输入描述：
 * 输入两手牌，两手牌之间用"-"连接，每手牌的每张牌以空格分隔，"-"两边没有空格，如 4 4 4 4-joker JOKER。
 *
 * 输出描述：
 * 输出两手牌中较大的那手，不含连接符，扑克牌顺序不变，仍以空格隔开；如果不存在比较关系则输出ERROR。
 *
 * 示例1
 * 输入：
 * 4 4 4 4-joker JOKER
 *
 * 输出：
 * joker JOKER
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;


string getResult(string poke)
{
    //拆分
    vector<string> p1, p2;
    string poke1 = poke.substr(0, poke.find('-'));
    string poke2 = poke.substr(poke.find('-')+1, poke.size()-poke.find('-')-1);
    unsigned int i = 0, j = 0;
    while(j < poke1.size()){
        if(poke1[j] == ' '){
            p1.push_back(poke1.substr(i, j-i));
            i = j+1;
        }
        j++;
    }
    p1.push_back(poke1.substr(i,j-i));
    i = 0, j = 0;
    while(j < poke2.size()){
        if(poke2[j] == ' '){
            p2.push_back(poke2.substr(i, j-i));
            i = j+1;
        }
        j++;
    }
    p2.push_back(poke2.substr(i,j-i));

    //比较
    unordered_map<string, int> index1, index2, index;
    vector<string> temp = {"3", "4", "5", "6", "7", "8","9","10", "J", "Q", "K", "A", "2", "joker", "JOKER"};
    for(string s: p1){
        index1[s]++;
    }
    for(string s: p2){
        index2[s]++;
    }
    for(int i = 0; i < int(temp.size()); i++){
        index[temp[i]] = i;
    }

    // 有无对王
    if(index1["joker"]>0 && index1["JOKER"]>0){
        return poke1;
    }
    if(index2["joker"]>0 && index2["JOKER"]>0){
        return poke2;
    }

    // 4个
    string card1 = "#", card2 = "#";
    for(auto iter=index1.begin(); iter != index1.end(); iter++){
        if(iter->second == 4) card1 = iter->first;
    }
    for(auto iter=index2.begin(); iter != index2.end(); iter++){
        if(iter->second == 4) card2 = iter->first;
    }
    if(card1 != "#" && card2 == "#"){
        return poke1;
    }else if(card1 == "#" && card2 != "#"){
        return poke2;
    }else if(card1 != "#" && card2 != "#"){
        if(index[card1] > index[card2]){
            return poke1;
        }else{
            return poke2;
        }
    }

    // 顺子
    if(p1.size() == 5 && p2.size() == 5){
        if(index[p1[0]] > index[p2[0]]){
            return poke1;
        }else{
            return poke2;
        }
    }

    // 3个
    if(p1.size() == 3 && p2.size() == 3){
        if(index[p1[0]] > index[p2[0]]){
            return poke1;
        }else{
            return poke2;
        }
    }

    // 2个
    if(p1.size() == 2 && p2.size() == 2){
        if(index[p1[0]] > index[p2[0]]){
            return poke1;
        }else{
            return poke2;
        }
    }

    // 1个
    if(p1.size() == 1 && p2.size() == 1){
        if(index[p1[0]] > index[p2[0]]){
            return poke1;
        }else{
            return poke2;
        }
    }

    return "ERROR";
}

int main()
{
    string poke;
    poke = "4 4 4 4-joker JOKER";
    cout << getResult(poke) << endl;
//    while(getline(cin, poke)){
//        cout << getResult(poke) << endl;
//    }
}


























