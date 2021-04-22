#include<stdio.h>

void foo(int n){
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= 5; j++){
            printf("%d ", j + i * 5);
        }
        printf("\n\n");
    }
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    foo(n);
    return 0;
}