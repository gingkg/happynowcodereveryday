/*HJ95 人民币转换
考试题目和要点：
1、中文大写金额数字前应标明“人民币”字样。中文大写金额数字应用壹、贰、叁、肆、伍、陆、柒、捌、玖、拾、佰、仟、万、亿、元、角、分、零、整等字样填写。
2、中文大写金额数字到“元”为止的，在“元”之后，应写“整字，如532.00应写成“人民币伍佰叁拾贰元整”。在”角“和”分“后面不写”整字。
3、阿拉伯数字中间有“0”时，中文大写要写“零”字，阿拉伯数字中间连续有几个“0”时，中文大写金额中间只写一个“零”字，如6007.14，应写成“人民币陆仟零柒元壹角肆分。
4、10应写作“拾”，100应写作“壹佰”。例如，1010.00应写作“人民币壹仟零拾元整”，110.00应写作“人民币壹佰拾元整”
5、十万以上的数字接千不用加“零”，例如，30105000.00应写作“人民币叁仟零拾万伍仟元整”
本题含有多组样例输入。

输入描述：
输入一个double数

输出描述：
输出人民币格式

输入：
151121.15
10012.02

输出：
人民币拾伍万壹仟壹佰贰拾壹元壹角伍分
人民币壹万零拾贰元贰分
*/

#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

vector<string> index = {"零","壹","贰","叁","肆","伍","陆","柒","捌","玖"};


string change4(vector<int> nums)
{
    //排除0
    int j = 0;
    while(nums[j] == 0){
        j++;
    }
    nums.assign(nums.begin()+j, nums.end());

    string res = "";

    int n = nums.size();
    if(n==4){
        res = res + index[nums[0]] + "仟";
        if(nums[1] == 0 && nums[2] == 0 && nums[3] == 0) return res;
        res = res + index[nums[1]];
        if(nums[1] != 0) res + "佰";
        if(nums[2] == 0 && nums[3] == 0) return res;
        if(nums[2] == 0){
            if(nums[1] != 0) res = res + index[nums[2]];
        }else{
            res = res + index[nums[2]] + "拾";
        }
        if(nums[3] == 0){
            return res;
        }else{
            res = res + index[nums[3]];
        }
    }
    if(n == 3){
        res = res + index[nums[0]] + "佰";
        if(nums[1] == 0 && nums[2] == 0) return res;
        res = res + index[nums[1]];
        if(nums[1] != 0) res = res + "拾";
        if(nums[2] == 0) return res;
        res = res + index[nums[2]];
    }
    if(n == 2){
        res = res + index[nums[0]] + "拾";
        if(nums[1] == 0) return res;
        res = res + index[nums[1]];
    }
    if(n == 1){
        res = res + index[nums[0]];
    }
    if(n == 0) res = "零";

    return res;
}

string change(vector<int> nums)
{
    string res = "";
    int n = nums.size();
    if(n > 8){
        res = res + change(vector<int>(nums.begin(), nums.end()-8)) + "亿";
        nums.assign(nums.begin()+(n-8), nums.end());
        n = 8;
        bool flag = true;
        for(int i = 0; i < 8; i++){
            if(nums[i] != 0){
                flag = false;
                break;
            }
        }
        if(flag) return res;
    }

    if(n > 4){
        string temp = change4(vector<int>(nums.begin(), nums.end()-4));
        if(res == ""){
            res = res + temp + "万";
        }else{
            if(temp.find("仟") == string::npos){
                if(temp == "零"){
                    res = res + temp;
                }else{
                    res = res + "零" + temp + "万";
                }
            }else{
                res = res + temp + "万";
            }
        }
        nums.assign(nums.begin()+(n-4), nums.end());
        n = 4;
        bool flag = true;
        for(int i = 0; i < 4; i++){
            if(nums[i] != 0){
                flag = false;
                break;
            }
        }
        if(flag) return res;
    }

    string temp = change4(nums);
    if(res == ""){
        res = temp;
    }else{
        if(temp.find("仟") == string::npos){
            res = res + "零" + temp;
        }else{
            res = res + temp;
        }
    }

    return res + "元";
}

string getResult(double num)
{
    string res = "人民币";
    int n1=0, n2=0;
    // 整数和小数分离
    double integer = floor(num);
    double decimal = num - integer;
    cout << integer << " " << decimal << endl;;

    //将整数部分拆分放入栈里
    stack<int> s1;
    while(integer > 0){
        s1.push(int((integer/10 - floor(integer/10))*10 + 0.5));
        integer = floor(integer/10);
        n1++;
    }

    vector<int> v1;
    while(!s1.empty()){
        v1.push_back(s1.top());
        s1.pop();
    }

    decimal = decimal * 100;
    stack<int> s2;
    bool flag = false;
    while(decimal > 0){
        int temp = int((decimal/10 - floor(decimal/10))*10 + 0.5);
        if (temp != 0) flag = true;
        if (flag){
            s2.push(temp);
            n2++;
        }
        decimal = floor(decimal/10);
    }

    //转换
    res = res + change(v1);
    if(n2 == 0){
        res = res + "整";
    }
    if(n2 == 1){
        res = res + index[s2.top()] + "角";
    }
    if(n2 == 2){
        if(s2.top() == 0){
            res = res + "零";
        }else{
            res = res + index[s2.top()] + "角";
        }
        s2.pop();
        res = res + index[s2.top()] + "分";
    }

    return res;
}

int main()
{
    double num;
    num = 12345678090.78;
    cout << getResult(num) << endl;
//    while(cin >> num){
//        cout << getResult(num) << endl;
//    }
}
