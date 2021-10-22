#include <iostream>

using namespace std;

unsigned long long NOD(unsigned long long a, unsigned long long b){
    while(a != 0 && b !=0){
        if(a > b){
            a %= b;
        }
        else{
            b %= a;
        }
    }
    return a+b;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        unsigned long long a, b;
        cin >> a >> b;
        cout << a * b / NOD(a, b) << endl;
    }
}