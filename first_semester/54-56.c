#include<stdio.h>

int min(int x, int n, int arr[]){
    int m = arr[x], ind = x;
    for(int i = x; i < n; i++){
        if(m > arr[i]){
            m = arr[i];
            ind = i;
        }
    }
    return ind;
}

int* bubble(int n, int arr[]){
    int b = 0;
    for(int i = 0; i < n - 1; i++){
        for(int j = 1; j < n - i; j++){
            if(arr[j - 1] > arr[j]){
                b = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = b;
            }
        }
    }
    return arr;
}

int* insertion(int n, int arr[]){
    int b = 0, j = 0;
    for(int i = 2; i < n; i++){
        j = i;
        while(j > 0 && arr[j] < arr[j - 1]){
            b = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = b;
            j--;
        }
    }
    return arr;
}

int* selection(int n, int arr[]){
    int b = 0, k = 0;
    for(int i = 0; i < n - 1; i++){
        k = min(i, n - i, arr);
        if(k != i){
            b = arr[k];
            arr[k] = arr[i];
            arr[i] = b;
        }
    }
    return arr;
}

void print(int n, int arr[]){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);   
    }
    print(n, bubble(n, arr));
    print(n, insertion(n, arr));
    print(n, selection(n, arr));
    return 0;
}