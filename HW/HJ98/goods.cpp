#include "goods.h"

Goods::Goods()
{
    name = "NONE";
    price = 0;
    num = 0;
}

Goods::Goods(string str, int i, int j)
{
    name = str;
    price = i;
    num = j;
}

void Goods::Init(int j)
{
    num = j;
}

void Goods::addGoods(int i)
{
    num = num + i;
}

void Goods::reduceGoods(int i)
{
    num = num - i;
}
