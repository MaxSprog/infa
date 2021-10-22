#include <iostream>
#include <cmath>

using namespace std;

int Div(int a, int b){
    if(a % b == 0){
        return a/b-1;
    }
    return a/b;
}

int main(){
    int n, m, p, k, l;
    cin >> n >> m >> p >> k >> l;
    int perfloor = ceil((double)m / (double)((p-1)*l+k));
    int Kall = ceil((double)n/(double)perfloor);
    // cout << perfloor << " " << Kall << endl;
    cout << ceil((double)Kall / (double)l) << " " << Kall - Div(Kall, l) * l;
}