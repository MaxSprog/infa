#include<stdio.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= n - i; j++){
            printf("%d ", j);
        }
        printf("\n");
    }
    printf("0");
    return 0;
}