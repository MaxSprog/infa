#include <stdio.h>
#include <stdlib.h>

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

void select(int n, int* arr){
    int b = 0, k = 0;
    for(int i = 0; i < n - 1; i++){
        k = min(i, n, arr);
        if(k != i){
            b = arr[k];
            arr[k] = arr[i];
            arr[i] = b;
        }
    }
}

int main(){
    int n = 0, x = 0, i = 0;
    scanf("%d", &n);
    int* arr = calloc(n, sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    select(n, arr);
    scanf("%d", &x);
    i = n / 2 - (n + 1) % 2;
    while(1){
        if(arr[i] == x){
            printf("found, index: %d", i);
            break;
        }
        if(n < 1){
            printf("nothing found");
            break;
        }
        n /= 2;
        if(x > arr[i]){
            i += n / 2 + (n/2 == 0);
            //printf("> %d %d\n", n, i);
        }
        else if(x < arr[i]){
            i -= n / 2 + (n/2 == 0);
            //printf("< %d %d\n", n, i);
        }
    }
    return 0;
}