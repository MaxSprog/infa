#include<stdio.h>

float max(int n, float arr[]){
    float M = arr[0];
    for(int i = 1; i < n; i++){
        if(M < arr[i]){
            M = arr[i];
        }
    }
    return M;
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    float arr[n];
    for(int i = 0; i < n; i++){
        scanf("%f", &arr[i]);
    }
    printf("%f", max(n, arr));
    return 0;
}