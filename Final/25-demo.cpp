#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int M, x, cnt = 0;
    for(x = 700001; ; x++){
        for(int i = 2; i <= sqrt(x); i++){
            if(x % i == 0){
                M = i + x/i;
                if(M % 10 == 8){
                    cout << x << " " << M << "\n";
                    cnt++;
                }
                break;
            }
        }
        if(cnt == 5)
            break;
    }
}