#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

void tri(double x1, double y1, double x2, double y2, double x3, double y3, int n){
    if(n == 1){
        cout << x1 << " " << y1 << '\n' << x2 << " " << y2 << "\n\n";
        cout << x1 << " " << y1 << '\n' << x3 << " " << y3 << "\n\n";
        cout << x2 << " " << y2 << '\n' << x3 << " " << y3 << "\n\n";
        return;
    }
    double a = x3 - x2;
    double Y12 = (y2 - y1)/2 + y1;
    double X12 = x2 + a / 4;
    
    double Y13 = Y12;
    double X13 = x2 + 3 * a / 4;

    double Y23 = y2;
    double X23 = x2 + a / 2;

    tri(x1, y1, X12, Y12, X13, Y13, n - 1);
    tri(X12, Y12, x2, y2, X23, Y23, n - 1);
    tri(X13, Y13, X23, Y23, x3, y3, n - 1);
}

int main(){
    ofstream f;
    f.open("triag.dat");
    int n;
    cin >> n;
    double a, x1, y1, x2, y2, x3, y3, pi = 3.14;
    cin >> a;
    x1 = a / 2;
    y1 = 0;
    x2 = 0;
    y2 = a * sin(pi / 3);
    x3 = a;
    y3 = y2;
    tri(x1, y1, x2, y2, x3, y3, n);
    f.close();
}