#include <iostream>
#include <cmath>

using namespace std;

int main(){
    unsigned int x, temp1, temp2;
    cin >> x;
    temp1 = x;
    temp2 = x;
    int val = 0;
    for(int i = 0; i < 32; i++){
        cout << ((temp1 & 2147483648) == 2147483648);
        temp1 <<= 1;
        val += (x & 1) * (int)pow(2, 31-i);
        x >>= 1;
    }
    cout << "\n" << val << "\n";
    for(int i = 0; i < 32; i++){
        cout << (temp2 & 1);
        temp2 >>= 1;
    }
}