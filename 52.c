#include<stdio.h>

int main()
{
    int n, N;
    scanf("%d %d", &n, &N);
    N = N % n;
    int arr[n], arr2[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < n; i++){
        arr2[i + N - (i + N >= n) * n + (i + N < 0) * n] = arr[i];
    }
    for(int i = 0; i < n; i++){
        printf("%d ", arr2[i]);
    }
    return 0;
}