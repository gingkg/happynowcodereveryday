#include "savingbox.h"

SavingBox::SavingBox()
{
    coins[1] = 0;
    coins[2] = 0;
    coins[5] = 0;
    coins[10] = 0;
}

SavingBox::SavingBox(unordered_map<int, int> &index)
{
    for(auto iter = index.begin(); iter != index.end(); iter++){
        coins[iter->first] = iter->second;
    }
}

void SavingBox::Init(unordered_map<int, int> &index)
{
    for(auto iter = index.begin(); iter != index.end(); iter++){
        coins[iter->first] = iter->second;
    }
}

void SavingBox::addCoin(int i, int j)
{
    coins[i] += j;
}

void SavingBox::reduceCoin(int i, int j)
{
    coins[i] -= j;
}

int SavingBox::getCoinNum(int i)
{
    if(coins.count(i)){
        return coins[i];
    }else{
        throw("输入错误");
    }
}
