#include <iostream>

using namespace std;

int main(){
    int k, x;
    cin >> k >> x;
    if(k-1 >= x && x >= 0)
        cout << "legal";
    else
        cout << "out of bounds";
}