#include <stdio.h>
#include <stdlib.h>

void print(int n, int arr[]){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int max(int n, int* arr){
    int M[2] = {arr[0], 0};
    for(int i = 1; i < n; i++){
        if(arr[i] > M[0]){
            M[0] = arr[i];
            M[1] = i;
        }
    }
    return M[1];
}

int min(int n, int* arr){
    int m[2] = {arr[0], 0};
    for(int i = 1; i < n; i++){
        if(arr[i] < m[0]){
            m[0] = arr[i];
            m[1] = i;
        }
    }
    return m[0];
}

void mergeto(int n1, int n2, int* arr1, int* arr2, int* arr3){
    int arrb[2];
    for(int i = 0; i < n1 + n2; i++){
        //printf("%d %d\n", max(n1, arr1), max(n2, arr2));
        //print(n1, arr1);
        //print(n2, arr2);
        if(arr1[max(n1, arr1)] > arr2[max(n2, arr2)] || (min(n2, arr2) == arr2[max(n2, arr2)] && i >= n2)){
            arr3 = realloc(arr3, (i + 1) * sizeof(int));
            arr3[i] = arr1[max(n1, arr1)];
            arr1[max(n1, arr1)] = min(n1, arr1);
            //printf("%d\n", min(n1, arr1));
        }
        else{
            arr3 = realloc(arr3, (i + 1) * sizeof(int));
            arr3[i] = arr2[max(n2, arr2)];
            arr2[max(n2, arr2)] = min(n2, arr2);
            //printf("%d\n", min(n2, arr2));
        }
    }
}

int main(){
    int n1 = 0, n2 = 0;
    scanf("%d %d", &n1, &n2);
    int* arr1;
    int* arr2;
    int* arr3;
    arr1 = malloc(sizeof(int)*n1);
    arr2 = malloc(sizeof(int)*n2);
    arr3 = malloc(sizeof(int));
    for(int i = 0; i < n1; i++){
        scanf("%d", &arr1[i]);
    }
    for(int i = 0; i < n2; i++){
        scanf("%d", &arr2[i]);
    }
    //arr1 = realloc(arr1, sizeof(int)*(n1-1));
    mergeto(n1, n2, arr1, arr2, arr3);

    print(n1+n2, arr3);
    return 0;
}