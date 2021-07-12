// 百钱买百鸡

#include <iostream>
#include <vector>
using namespace std;

int GetResult(vector<vector<int>>& list) {
    int money = 100;
    int n = 100;
    for (int i = 0; i < money / 5; i++) {
        for (int j = 0; j < (money - i * 5) / 3; j++) {
            int restMoney = money - i * 5 - j * 3;
            int restN = n - i - j;
            if (restN == restMoney * 3) {
                // 成立
                list.push_back({ i, j, restN });
            }
        }
    }
    return 0;
}

int GetResult2(vector<vector<int>>& list) {
    for (int i = 0; i <= 3; i++) {
        list.push_back({ i * 4, 25 - 7 * i, 100 - i * 4 - (25 - 7 * i) });
    }
    return 0;
}


int main() {
    int a;
    while (cin >> a) { // 注意 while 处理多个 case
        vector<vector<int>> list;
        GetResult2(list);
        for (int i = 0; i < list.size(); i++) {
            for (int j = 0; j < list[i].size(); j++) {
                cout << list[i][j] << " ";
            }
            cout << endl;
        }

    }
}
