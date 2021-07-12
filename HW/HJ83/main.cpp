/*
 *HJ83 二维数组操作
 */

#include <iostream>
#include <vector>
using namespace std;


class data
{
private:
    int M = 0;
    int N = 0;
    int mMax = 9;
    int nMax = 9;

public:
    data(){}
    ~data(){}

public:
    bool init(int m, int n){
        if(m <= mMax && n <= nMax){
            M = m;
            N = n;
            return true;
        }else{
            M = min(m, mMax);
            N = min(n, nMax);
            return false;
        }
    }

    bool swap(int x1, int y1, int x2, int y2){
        if(0 <= x1 && x1 < M && 0 <= y1 && y1 < N &&
                0 <= x2 && x2 < M && 0 <= y2 && y2 < N){
            return true;
        }else{
            return false;
        }
    }

    bool insertRow(int x){
        if(0 <= x && x < M){
            if(M+1 <= mMax){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    }

    bool insertColumn(int y){
        if(0 <= y && y < N){
            if(N+1 <= nMax){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    }

    bool query(int x, int y){
        if(0 <= x && x < M && 0 <= y && y < N){
            return true;
        }else{
            return false;
        }
    }
};


int main()
{
    int m, n;
    int x1, y1, x2, y2;
    int x, y;
    while(cin >> m >> n){
        data D;
        if(D.init(m,n)){
            cout << 0 << endl;
        }else{
            cout << -1 << endl;
        }

        cin >> x1 >> y1 >> x2 >> y2;
        if(D.swap(x1, y1, x2, y2)){
            cout << 0 << endl;
        }else{
            cout << -1 << endl;
        }

        cin >> x;
        if(D.insertRow(x)){
            cout << 0 << endl;
        }else{
            cout << -1 << endl;
        }

        cin >> y;
        if(D.insertColumn(y)){
            cout << 0 << endl;
        }else{
            cout << -1 << endl;
        }

        cin >> x >> y;
        if(D.query(x, y)){
            cout << 0 << endl;
        }else{
            cout << -1 << endl;
        }
    }
}



