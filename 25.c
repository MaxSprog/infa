#include<stdio.h>

int main()
{
    int n = 1, i = 0;
    printf("%d\n", n);
    while(1){
        if(i % 2 == 0 && n + 1 <= 100){
            n += 1;
        }
        else if(i % 2 != 0 && n * 2 <= 100){
            n *= 2;
        }
        else{
            break;
        }
        printf("%d\n", n);
        i++;
    }
    return 0;
}