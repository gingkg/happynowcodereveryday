#ifndef SAVINGBOX_H
#define SAVINGBOX_H

#include <unordered_map>
using namespace std;

class SavingBox
{
private:
    unordered_map<int, int> coins;
public:
    SavingBox();
    SavingBox(unordered_map<int, int>& index);
    unordered_map<int, int>& COINS(){return coins;};
    void Init(unordered_map<int, int>& index);
    void addCoin(int i, int j=1);
    void reduceCoin(int i, int j=1);
    int getCoinNum(int i);
};

#endif // SAVINGBOX_H
