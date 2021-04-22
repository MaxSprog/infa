#include<stdio.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);   
    }
    int b = 0;
    for(int i = 0; i < n / 2; i++){
        b = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = b;
    }
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}