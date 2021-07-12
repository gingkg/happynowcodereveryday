/*
 * HJ87 密码强度等级
密码按如下规则进行计分，并根据不同的得分为密码进行安全等级划分。

一、密码长度:
5 分: 小于等于4 个字符
10 分: 5 到7 字符
25 分: 大于等于8 个字符

二、字母:
0 分: 没有字母
10 分: 全都是小（大）写字母
20 分: 大小写混合字母

三、数字:
0 分: 没有数字
10 分: 1 个数字
20 分: 大于1 个数字

四、符号:
0 分: 没有符号
10 分: 1 个符号
25 分: 大于1 个符号

五、奖励:
2 分: 字母和数字
3 分: 字母、数字和符号
5 分: 大小写字母、数字和符号

最后的评分标准:
>= 90: 非常安全
>= 80: 安全（Secure）
>= 70: 非常强
>= 60: 强（Strong）
>= 50: 一般（Average）
>= 25: 弱（Weak）
>= 0:  非常弱

对应输出为：
VERY_SECURE
SECURE,
VERY_STRONG,
STRONG,
AVERAGE,
WEAK,
VERY_WEAK,

请根据输入的密码字符串，进行安全评定。

注：
字母：a-z, A-Z
数字：0-9

符号包含如下： (ASCII码表可以在UltraEdit的菜单view->ASCII Table查看)
!"#$%&'()*+,-./     (ASCII码：x21~0x2F)
:;<=>?@             (ASCII<=><=><=><=><=>码：x3A~0x40)
[\]^_`              (ASCII码：x5B~0x60)
{|}~                (ASCII码：x7B~0x7E)

输入描述：
本题含有多组输入样例。
每组样例输入一个string的密码

输出描述：
每组样例输出密码等级

示例1
输入：
38$@NoNoNo
123

输出：
VERY_SECURE
WEAK

说明：
第一组样例密码强度为95分。
第二组样例密码强度为25分。
*/


#include <iostream>
#include <string>
using namespace std;

string getResult(string str)
{
    int score = 0;
    // 一、密码长度
    if(str.size() <= 4){
        score += 5;
    }else if(str.size() < 8)
    {
        score += 10;
    }else{
        score += 25;
    }

    // 统计字母、数字和符号的个数
    int count[4] = {0, 0, 0, 0};
    for(char c: str){
        if('a' <= c && c <= 'z'){
            count[0]++;
        }else if('A' <= c && c <= 'Z'){
            count[1]++;
        }else if('0' <= c && c <= '9'){
            count[2]++;
        }else{
            count[3]++;
        }
    }

    if((count[0] == 0 && count[1] > 0) || (count[0] > 0 && count[1] == 0)){
        score += 10;
    }
    if(count[0] > 0 && count[1] > 0){
        score += 20;
    }

    if(count[2] == 1){
        score += 10;
    }
    if(count[2] > 1){
        score += 20;
    }

    if(count[3] == 1){
        score += 10;
    }
    if(count[3] > 1){
        score += 25;
    }

    if(count[0] > 0 && count[1] > 0 && count[2] > 0 && count[3] > 0){
        score += 5;
    }else if((count[0] + count[1]) > 0 && count[2] > 0 && count[3] > 0){
        score += 3;
    }else if((count[0] + count[1]) > 0 && count[2] > 0){
        score += 2;
    }

    cout << count[0] << " " << count[1] << " " << count[2] << " " << count[3] << endl;

    cout << score << endl;

    if(score >= 90){
        return "VERY_SECURE";
    }else if(score >= 80){
        return "SECURE";
    }else if(score >= 70){
        return "VERY_STRONG";
    }else if(score >= 60){
        return "STRONG";
    }else if(score >= 50){
        return "AVERAGE";
    }else if(score >= 25){
        return "WEAK";
    }else{
        return "VERY_WEAK";
    }
}

int main()
{
    string str;
    str = "J%PZ#n^wMEdr@OkD&`gIZ#R*&fZO^!)M(UY`C@t)fcjhXEKFwW#cXB@gc$vVkGTf!@Ne$e&`^mID!vw`#xs&#*UECHMoBLbn#XGnNYu(Ic$vAkVtdCsti)y(c)!JqN%\
            PKyt&&fmE^`aBC)t$`Jh^^Rxr(EQ&!N(u)^)`";

    cout << getResult(str) << endl;
//    while(getline(cin, str))
//    {
//        cout << getResult(str) << endl;
//    }
}









