#include <iostream>

using namespace std;

int main(){
    int k;
    cin >> k;
    int c = 0;
    for(int i = 1; c < k; i++){
        if(c + 1 == k){
            cout << 1;
            return 0;
        }
        c += i;
    }
    cout << 0;
}