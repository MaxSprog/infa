#include<stdio.h>

void foo(int m, int n){
    for(int i = 0; i < m; i++){
        if(i % 2 == 0){
            for(int j = 0; j <= n; j++){
                printf("%d ", j);
            }
        }
        else{
            for(int j = 0; j <= n; j++){
                printf("%d ", n - j);
            }
        }
        printf("\n\n");
    }
}

int main()
{
    int m = 0, n = 0;
    scanf("%d %d", &m, &n);
    foo(m, n);
    return 0;
}