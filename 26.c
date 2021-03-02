#include<stdio.h>

void Fib1(int n){
    int p1 = 1, p2 = 1, buf = 0;
    if(n <= 0){
        return;}
    else if(n == 1){
        printf("1\n");
        return;
    }
    printf("1\n1\n");
    for(int i = 0; i < n - 2; i++){
        buf = p1;
        p1 = p2;
        p2 = buf + p2;
        printf("%d\n", p2);
    }
}

void Fib2(int n){
    int p1 = 1, p2 = 1, buf = 0;
    if(n <= 0){
        return;}
    else if(n == 1){
        printf("2\n");
        return;
    }
    printf("2\n2\n");
    for(int i = 0; i < n - 2; i++){
        buf = p1;
        p1 = p2;
        p2 = buf + p2;
        printf("%d\n", 2 * p2);
    }
}

void FibAB(int a, int b, int n){
    int buf = 0;
    if(n <= 0){
        return;}
    else if(n == 1){
        printf("%d\n", a);
        return;
    }
    printf("%d\n%d\n", a, b);
    for(int i = 0; i < n - 2; i++){
        buf = a;
        a = b;
        b = buf + b;
        printf("%d\n", b);
    }
}

int main()
{
    int n = 0, a = 0, b = 0;
    scanf("%d", &n);
    Fib1(n);
    printf("\n");
    scanf("%d", &n);
    Fib2(n);
    printf("\n");
    scanf("%d %d %d", &a, &b, &n);
    FibAB(a, b, n);
    return 0;
}