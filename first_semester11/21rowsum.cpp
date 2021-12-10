#include <iostream>
#include <iomanip>

using namespace std;
#define abs(a) (a >= 0 ? a : -a)

double Pow(double x, int a){
    double c = 1;
    for(int i = 0; i < a; i++){
        c *= x;
    }
    // cout << "c: " << c << endl;
    return c;
}


int main(){
    cout.precision(5);
    double x, eps;
    cin >> x >> eps;
    double c = 0;
    double p=1;
    double pow = x;
    for(int i = 0; abs(p) * 1000000 >= 1; i++){
        p = (-2 * (i % 2 != 0)+1)*Pow(x, 2*i+1)/(2*i+1);
        // cout << "p: " << p << endl;
        c += p;
        if(abs(p) < eps)
            break;
    }
    cout << fixed << c;
}