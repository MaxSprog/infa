#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int n;
    int S = 0;
    int mind = 1000000;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        S += max(a, b);
        if(abs(a - b) % 3 != 0 && abs(a - b) < mind){
            mind = abs(a - b);
        }
    }
    if(S % 3 != 0) cout << S << endl;
    else cout << S - mind << endl;
}