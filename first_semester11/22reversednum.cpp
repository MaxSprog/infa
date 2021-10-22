#include <iostream>

using namespace std;

int Pow(int x, int a){
    int c = 1;
    for(int i = 0; i < a; i++){
        c *= x;
    }
    return c;
}

int length(int x){
    int i = 1;
    for(; (x /= 10) != 0; i++){}
    return i;
}

int main(){
    int n;
    cin >> n;
    int c;
    for(int i = 1; i <= length(n); i++){
        c = n % Pow(10, i);
        // cout << "c: " << Pow(10, i) << " " << n % Pow(10, i) << endl;
        if(c != 0)
            cout << c / Pow(10, i-1);
    }
}
