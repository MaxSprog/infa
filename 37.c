#include<stdio.h>
#include<math.h>

int fib(double n){
    return (int)((pow((double)(1 + sqrt(5))/2, n) - pow((double)(1 - sqrt(5))/2, n))/sqrt(5));
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    printf("%d", fib(n));
    return 0;
}