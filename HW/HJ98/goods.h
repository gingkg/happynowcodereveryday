#ifndef GOODS_H
#define GOODS_H
#include <string>
using namespace std;

class Goods
{
private:
    string name;
    int price;
    int num;

public:
    Goods();
    Goods(string str, int i, int j);
    void Init(int j);
    string& NAME(){return name;}
    int& PRICE(){return price;}
    int& NUM(){return num;}
    void addGoods(int i = 1);
    void reduceGoods(int i = 1);
};

#endif // GOODS_H
