#include<stdio.h>
#include <stdlib.h>
#include <math.h>

double mult(double n, double* arr){
    double res = 1.0;
    for(int i = 0; i < n; i++){
        res *= arr[i];
    }
    return res;
}

double sum(double n, double* arr){
    double M = 0;
    for(int i = 0; i < n; i++){
        M += arr[i];
    }
    return M;
}

int main()
{
    int n;
    scanf("%d", &n);
    double* arr = malloc(n * sizeof(double));
    for(int i = 0; i < n; i++){
        scanf("%lf", &arr[i]);
    }
    printf("%lf\n", sum(n, arr) / n);
    printf("%lf", pow(mult(n, arr), 1 / n) * (mult(n, arr) != 0));
    return 0;
}