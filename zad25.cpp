#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int c;
    for(int i = 174457; i <= 174505; i++){
        c = -1;
        for(int j = 2; j <= sqrt(i); j++){
            if(i % j == 0){
                if(c != -1){
                    c = -1;
                    break;
                }
                c = j;
            }
        }
        if(c != -1 && i / c != c){
            printf("%d %d\n", c, i / c);
        }
    }
}
//174457 174505