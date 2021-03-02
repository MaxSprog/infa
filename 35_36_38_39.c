#include<stdio.h>
#include<stdlib.h>

int len(int x){
    int i = 0;
    while(x > 0){
        i += 1;
        x /= 10;
    }
    return i;
}

int max(int a, int b){
    if(a > b)
        return a;
    return b;
}

float Sum(float n1, float n2){
    return n1 + n2;
}
float Dif(float n1, float n2){
    return n1 - n2;
}
float Mult(float n1, float n2){
    return n1 * n2;
}
float Div(float n1, float n2){
    return n1 / n2;
}

int fac(int n){
    if(n <= 1){
        return 1;
    }
    return n * fac(n-1); 
}

float Pow(float a, int n){
    int b = a;
    if(n == 0){
        return 1;
    }
    for(int i = 1; i < abs(n); i++){
        a *= b;
    }
    if(n < 0)
        return 1 / a;
    return a;
}

int kon(int a, int b){
    int abin = 0, bbin = 0, ansbin = 0, i = 1, ans = 0;
    while(1){
        abin += a % 2 * i;
        if(a <= 1)
            break;
        a /= 2;
        i *= 10;
    }
    i = 1;
    while(1){
        bbin += b % 2 * i;
        if(b <= 1)
            break;
        b /= 2;
        i *= 10;
    }
    //printf("%d %d\n", abin, bbin);
    for(i = 0; i < max(len(abin), len(bbin)); i++){
        ansbin += (((abin / (int)Pow(10, i) - abin / (int)Pow(10, i + 1) * 10) % (int)Pow(10, i + 1)) && ((bbin / (int)Pow(10, i) - bbin / (int)Pow(10, i + 1) * 10) % (int)Pow(10, i + 1))) * (int)Pow(10, i);
    }
    //printf("%d\n", ansbin);
    for(i = len(ansbin) - 1; i >= 0; i--){
        ans += (ansbin / (int)Pow(10, i) - ansbin / (int)Pow(10, i + 1) * 10) * (int)Pow(2, i);
    }
    return ans;
}

int diz(int a, int b){
    int abin = 0, bbin = 0, ansbin = 0, i = 1, ans = 0;
    while(1){
        abin += a % 2 * i;
        if(a <= 1)
            break;
        a /= 2;
        i *= 10;
    }
    i = 1;
    while(1){
        bbin += b % 2 * i;
        if(b <= 1)
            break;
        b /= 2;
        i *= 10;
    }
    //printf("%d %d\n", abin, bbin);
    for(i = 0; i < max(len(abin), len(bbin)); i++){
        ansbin += (((abin / (int)Pow(10, i) - abin / (int)Pow(10, i + 1) * 10) % (int)Pow(10, i + 1)) || ((bbin / (int)Pow(10, i) - bbin / (int)Pow(10, i + 1) * 10) % (int)Pow(10, i + 1))) * (int)Pow(10, i);
    }
    //printf("%d\n", ansbin);
    for(i = len(ansbin) - 1; i >= 0; i--){
        ans += (ansbin / (int)Pow(10, i) - ansbin / (int)Pow(10, i + 1) * 10) * (int)Pow(2, i);
    }
    return ans;
}

int main()
{
    float n1, n2;
    int a, b;
    scanf("%f %f", &n1, &n2);
    printf("%f\n", Sum(n1, n2));
    printf("%f\n", Dif(n1, n2));
    printf("%f\n", Mult(n1, n2));
    printf("%f\n", Div(n1, n2));
    scanf("%d %d", &a, &b);
    printf("%d\n", kon(a, b));
    printf("%d\n", diz(a, b));
    scanf("%d", &a);
    printf("%d\n", fac(a));
    scanf("%f %d", &n1, &a);
    printf("%f\n", Pow(n1, a));
    return 0;
}