#include<stdio.h>
#include <math.h>

int main(){
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    if(a == b && b == 0){
        if(c != 0){
            printf("wrong equation coefficients");
            return 0;
        }
        else{
            printf("any");
            return 0;
        }
    }
    else if(a == 0){
        printf("%lf", -c / b);
    }
    else{
        double D = b * b - 4 * a * c;
        if(D > 0){
            printf("%lf %lf", (-b + sqrt(D)) / (2 * a), (-b - sqrt(D)) / (2 * a));
            return 0;
        }
        else if(D == 0){
            printf("%lf", (-b + sqrt(D)) / (2 * a));
            return 0;
        }
        else{
            printf("no solutions");
            return 0;
        }
    }
}