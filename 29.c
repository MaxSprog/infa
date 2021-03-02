#include<stdio.h>

void foo(int n){
    for(int i = 0; i < n; i++){
        printf("1 2 3 4 5\n\n");
    }
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    foo(n);
    return 0;
}