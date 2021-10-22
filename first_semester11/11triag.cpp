#include <iostream>
// #include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    // cout.precision(3);
    int xa, ya, xb, yb, xc, yc;
    // ifstream fin("input.txt");
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    // fin.close();
    double ab = sqrt(pow(xa - xb, 2) + pow(ya - yb, 2));
    double bc = sqrt(pow(xb - xc, 2) + pow(yb - yc, 2));
    double ca = sqrt(pow(xc - xa, 2) + pow(yc - ya, 2));
    // ofstream fout("output.txt");
    cout << fixed << setprecision(3) << ab + bc + ca << endl;
    double p = (ab + bc + ca)/2;
    cout << fixed << setprecision(3) << sqrt(p*(p-ab)*(p-bc)*(p-ca));
}