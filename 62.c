#include<stdio.h>

void swap(int*a, int*b){
    int c = *b;
    *b = *a;
    *a = c;
}

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d %d\n", a, b);
    swap(&a, &b);
    printf("%d %d", a, b);
    return 0;
}