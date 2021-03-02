#include <stdio.h> 
#include <math.h> 
 
 
unsigned long long int factorial(int n) 
{ 
 if (n == 0) 
     return 1; 
 unsigned long long int a = 1; 
 for (int i = 1; i <= n; i++) 
 { 
     a *= i; 
 } 
 return a; 
} 
 
int main(){ 
    double n, m = 1; 
    scanf("%lf", &n);

    for (int i = 1; i <= 22; i++) { 
        m += (double)pow(n, i) / (double)factorial(i); 
    } 
 
    printf("%lf", m); 
}
