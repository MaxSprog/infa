#include <stdio.h> 
#include <math.h> 
 
unsigned long long int factorial(int n) 
{ 
    if (n == 0) 
        return 1; 
    unsigned long long int res = 1; 
    for (int i = 1; i <= n; i++) { 
        res *= i; 
    } 
    return res; 
}

double Sin(double n){
    double res = 0;
    n = n * M_PI / 180;
    for (int i = 0; i < 15; i++){ 
        res += pow(-1, i) * pow(n, 2 * i + 1) / (double)factorial(2 * i + 1);
    }
    return res;
}

double Cos(double n){
    double res = 0;
    n = n*M_PI/180;
    for (int i = 0; i < 15; i++) 
    { 
        res += (double)(pow(-1, i) * pow(n, 2*i))/(double)factorial(2*i); 
    }
    return res;
}
 
int main() 
{ 
 double n;
 scanf("%lf", &n);
 printf("%lf\n", Sin(n));
 printf("%lf", Cos(n));
}