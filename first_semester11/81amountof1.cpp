#include <iostream>

using namespace std;

int main(){
    unsigned int x, c = 0, M = 0;
    cin >> x;
    for(; x; x >>= 1){
        if(x & 1){
            c += 1;
        }
        else{
            M = c > M ? c : M;
            c = 0;
        }
    }
    cout << (M > c ? M : c);
}