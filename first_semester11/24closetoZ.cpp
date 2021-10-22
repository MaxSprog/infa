#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, ind;
    cin >> n;
    double m = 101, last;
    for(int i = 1; i <= n; i++){
        cin >> last;
        last -= (int)last;
        last = abs(last);
        last = min(1 - last, last);
        if(last < m){
            ind = i;
            m = last;
        }
    }
    cout << ind;
}