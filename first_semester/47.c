#include<stdio.h>
#include <stdlib.h>

int min(int n, int* arr){
    int m = arr[0];
    for(int i = 1; i < n; i++){
        if(m > arr[i]){
            m = arr[i];
        }
    }
    return m;
}

int max(int n, int* arr){
    int M = arr[0];
    for(int i = 1; i < n; i++){
        if(M < arr[i]){
            M = arr[i];
        }
    }
    return M;
}

int main()
{
    const int n;
    scanf("%d", &n);
    int* arr = calloc(n, sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("min=%d\n", min(n, arr));
    printf("max=%d\n", max(n, arr));
    return 0;
}