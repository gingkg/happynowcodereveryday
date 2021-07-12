#ifndef VENDINGSYSTEM_H
#define VENDINGSYSTEM_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "goods.h"
#include "savingbox.h"
using namespace std;

class VendingSystem
{
private:
    vector<string> names = {"A1", "A2", "A3", "A4", "A5", "A6"};
    vector<int> prices = {2,3,4,5,8,6};
    vector<Goods> shops;
    vector<int> coins = {1,2,5,10};
    SavingBox box;
    int balance;  // 投币余额

public:
    VendingSystem();
    void Run(string str);
    void Init(string str);
    void Pay(string str);
    void Buy(string str);
    void Change();
    void Query(string str);
    static bool cmp(Goods g1, Goods g2);
};

#endif // VENDINGSYSTEM_H
