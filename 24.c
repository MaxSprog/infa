#include<stdio.h>

int main()
{
    int n = 0;
    for(int i = 0; n + i <= 100; i++){
        n += 2 * i + 1;
        printf("%d\n", n);
    }
    return 0;
}