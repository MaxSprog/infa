#include "stdio.h"
#include "stdlib.h"

int min(int x, int n, int* arr){
    int m = arr[x], ind = x;
    for(int i = x; i < n; i++){
        if(m > arr[i]){
            m = arr[i];
            ind = i;
        }
    }
    return ind;
}

void select(int n, int st, int* arr){
    int b = 0, k = 0;
    for(int i = st; i < n - 1; i++){
        k = min(i, n, arr);
        if(k != i){
            b = arr[k];
            arr[k] = arr[i];
            arr[i] = b;
        }
    }
}

void printarr(int n, int* arr){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int n = 0, k = 0, min = 0, i_min = 0;
    scanf("%d", &n);
    int* M = calloc(n, sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%d", &M[i]);
    }
    for(int i = n-1; i > 0; i--){
        if(M[i-1] < M[i]){
            k = i;
            break;
        }
    }
    min = M[k];
    for(int i = k; i < n; i++){
        if(M[i] > M[n]){
            if(M[i] < min){
                i_min = i;
                min = M[i];
            }
        }
    }
    int p = M[i_min - 1];
    M[i_min - 1] = M[k - 1];
    M[k - 1] = p;
    select(n, k, M);
    printarr(n, M);
    return 0;
}