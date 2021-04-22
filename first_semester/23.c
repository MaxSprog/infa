#include<stdio.h>

int main()
{
    int n = 1;
    for(int i = 0; n + i + 1 <= 100; i++){
        n += i;
        printf("%d\n", n);
    }
    return 0;
}