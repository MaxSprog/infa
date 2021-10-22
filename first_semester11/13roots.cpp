#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){
    double a, b, c;
    cin >> a >> b >> c;
    if(a == b && b == 0){
        if(c != 0){
            cout << "ERROR";
            return 0;
        }
        else{
            cout << "MANY";
            return 0;
        }
    }
    else if(a == 0){
        cout << 1 << endl;
        cout << fixed << setprecision(5) << -c / b;
    }
    else{
        double D = b * b - 4 * a * c;
        if(D > 0){
            cout << 2 << endl;
            double x1 = (-b + sqrt(D)) / (2 * a), x2 = (-b - sqrt(D)) / (2 * a);
            cout << fixed << setprecision(5) << min(x1, x2) << " " << max(x1, x2);
            return 0;
        }
        else if(D == 0){
            cout << 1 << endl;
            cout << fixed << setprecision(5) << (-b + sqrt(D)) / (2 * a);
            return 0;
        }
        else{
            cout << "NO";
            return 0;
        }
    }
}