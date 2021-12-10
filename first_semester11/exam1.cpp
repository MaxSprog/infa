#include <iostream>
using namespace std;
#define abs(a) (a >= 0 ? a : -a)

int main(){
    cout.precision(5);
    double x, eps, slag, pow, k;
    cin >> x >> eps;
    slag = x;
    pow = x;
    k = x;
    x = 0;
    for(int i = 1; abs(slag) >= eps; i++){
        x += (((i-1) % 2 == 0) ? slag : -slag);
        k *= pow*pow;
        slag = k / (2*i+1);
    }
    cout << fixed << x;
    return 0;
}