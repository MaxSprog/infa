#include <iostream>
#include <algorithm>

using namespace std;

unsigned long int fact(int x){
    unsigned long int n = 1;
    for(int i = 2; i <= x; i++){
        n *= i;
    }
    return n;
}

// int C(int n, int k){

// }

int main(){
    int P, V;
    unsigned long int sum = 1;
    for(int i = 0; i < 3; i++){
        cin >> P >> V;
        sum *= fact(P+V-1) / (fact(min(P, V))*fact(P+V-1-min(P, V)));
    }
    cout << sum;
}