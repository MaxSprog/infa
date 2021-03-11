#include <iostream>

using namespace std;

int main(){
    int n;
    int S = 0;
    int mind = 1000000;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        if(a > b){
            S += a;
            if((a - b) % 3 != 0 && (a - b) < mind){
                mind = a - b;
            }
        }
        else{
            S += b;
            if((b - a) % 3 != 0 && (b - a) < mind){
                mind = b - a;
            }
        }
        if(S % 3 != 0) cout << S << endl;
        else cout << S - mind << endl;
    }

}