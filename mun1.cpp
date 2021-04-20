#include <iostream>

using namespace std;

int num(int i){
    int n = 1;
    for(int j = 0; j < i - 1; j++){
        n *= 10;
        n += 1;
    }
    return n;
}

int main(){
    int d, n;
    cin >> d >> n;
    int i, j;
    for(i = 0; n != 0; i++){
        for(j = 0; num(j) * d <= n; j++){}
        n -= num(j) * d / 10;
    }
    cout << i - 1;
}