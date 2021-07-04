// HJ28.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
// 二分图最大匹配
// 匈牙利算法

#include<vector>
#include<list>
#include<iostream>
using namespace std;

class HungarianAlgorithm
{
public:
    typedef std::list< std::pair<size_t, size_t> > pairmatch;
private:
    bool** graph;
    size_t* match;
    bool* request;
    bool dfs(size_t i, size_t ny)
    {
        for (size_t j = 0; j < ny; ++j)
            if (graph[i][j] && request[j])
            {
                request[j] = false;
                if (match[j] == -1 || dfs(match[j], ny))
                {
                    match[j] = i;
                    return request[j] = true;
                }
            }
        return false;
    }
protected:
    pairmatch pairlist;
public:
    template<class type>
    HungarianAlgorithm(type const& G, size_t nx, size_t ny)
    {
        if (nx && ny)
        {
            graph = new bool* [nx];
            for (size_t i = 0; i < nx; ++i)
                graph[i] = new bool[ny];
            match = new size_t[ny];
            request = new bool[ny];

            for (size_t i = 0; i < nx; ++i)
                for (size_t j = 0; j < ny; ++j)
                    graph[i][j] = G(i, j);

            for (size_t j = 0; j < ny; ++j)
                match[j] = -1;

            for (size_t j = 0; j < ny; ++j)
                request[j] = true;

            for (size_t i = 0; i < nx; ++i)
                dfs(i, ny);

            for (size_t j = 0; j < ny; ++j)
                if (match[j] != -1)
                    pairlist.emplace_back(match[j], j);

            for (size_t i = 0; i < nx; ++i)
                delete[] graph[i];
            delete[] graph;
            delete[] match;
            delete[] request;
        }
    }
    pairmatch const& getmatch()const { return pairlist; }
};

bool isPrime(size_t n)
{
    for (size_t i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return false;
    return true;
}

int main(void)
{
    size_t n;
    size_t data;
    while (cin >> n)
    {
        vector< size_t > X, Y;
        X.reserve(n);
        Y.reserve(n);
        size_t nx = 0;
        size_t ny = 0;
        for (size_t i = 0; i < n; ++i)
        {
            cin >> data;
            if (data % 2)
                X[nx++] = data;
            else
                Y[ny++] = data;
        }

        auto G = [&](size_t i, size_t j) {return isPrime(X[i] + Y[j]); };

        auto p = HungarianAlgorithm(G, nx, ny).getmatch();

        cout << p.size() << endl;
    }
    return 0;
}
