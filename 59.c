#include <stdio.h>
#include <stdlib.h>

int main(){
    double e1 = 1.0;
    float e2 = 1.0f;
    while(!(1.0 + e1/2 == 1.0 && 1.0 + e1 != 1.0)){
        e1 /= 2.0;
    }
    while(1){
        if(1 + e2/2 == 1 && 1 + e2 != 1)
            break;
        e2 /= 2;
    }
    printf("%e\n", e1);
    printf("%e\n", e2);
    //printf("%d\n", 1 == 1 + e1/2);
    //printf("%d", 1 + e1 == 1 + e1 + e1/2);
    return 0;
}