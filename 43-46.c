#include<stdio.h>

int main()
{
    const int n;
    scanf("%d", &n);
    int arr[n], arr2[n], arr3[n], arr4[n];
    for(int i = 1; i <= n; i++){
        arr[i] = i;
        arr2[i] = arr[i] * 2;
        arr3[i] = arr2[i] - 1;
        arr4[i] *= 2;
    }
    return 0;
}