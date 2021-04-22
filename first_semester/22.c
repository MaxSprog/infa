#include<stdio.h>
#include<stdlib.h>

unsigned long long sqrsum(int n, long long* arr){
    unsigned long long sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i]*arr[i];
    }
    return sum;
}

int sum(int i, int n, long long* arr){
    int s = i - 9, sum = 0;
    if(s < 0){
        i = s + 9;
        s = 0;
    }
    for(int j = s; j <= i; j++){
        if(j >= n)
            break;
        sum += arr[j];
    }
    return sum;
}

int main(){
    int num = 0, n = 0, size = 10;
    scanf("%d", &num);
    if(num % 2 == 1 || num <= 0){
        printf("unacceptable number");
        return 0;
    }
    long long* tick1 = malloc(size * sizeof(long long));
    long long* tick2 = malloc(size * sizeof(long long));
    //int* tick2 = calloc(1, sizeof(int));
    for(int i = 0; i < size; i++){
        tick1[i] = 1;
        tick2[i] = 1;
    }
    for(int i = 0; i < num / 2 - 1; i++){
        size += 9;
        tick2 = realloc(tick2, size * sizeof(long long));
        for(int j = 0; j < size; j++){
            tick2[j] = sum(j, size - 9, tick1);
        }
        tick1 = realloc(tick1, sizeof(long long) * size);
        for(int j = 0; j < size; j++){
            tick1[j] = tick2[j];
        }
    }
    printf("%llu", sqrsum(size, tick1));
    return 0;
}
