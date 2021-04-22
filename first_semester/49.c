#include<stdio.h>
#include <stdlib.h>

int main(){
    int n = 0, cnt = 0;
    scanf("%d", &n);
    int* arr = calloc(n, sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    for(int i = 1; i < n; i++){
        if(arr[i - 1] > arr[i])
            cnt++;
    }
    printf("%d", cnt);
    return 0;
}