#include <stdio.h>
#include <stdlib.h>

size_t strlen(const char *str){
    size_t i = 0;
    while(str[i++] != '\0'){}
    return i - 1;
}

int min(int a, int b){
    return a > b ? b : a;
}

void printarr(int n, int m, int** arr){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main(){
    char* s1 = "abcabba";
    char* s2 = "baca";
    int n1 = strlen(s1) + 1;
    int n2 = strlen(s2) + 1;
    int** arr = (int**)malloc(n1 * sizeof(int*));
    for(int i = 0; i < n1; i++){
        arr[i] = (int*)calloc(n2, sizeof(int));
    }
    for(int i = 0; i < n1; i++){
        arr[i][0] = i;
    }
    for(int i = 0; i < n2; i++){
        arr[0][i] = i;
    }
    for(int i = 1; i < n1; i++){
        for(int j = 1; j < n2; j++){
            if(s1[i - 1] != s2[j - 1]){
                //printf("!=%c %c, %d %d\n", s1[i - 1], s2[j - 1], i, j);
                arr[i][j] = min(arr[i-1][j] + 1, arr[i][j-1] + 1);
            }
            else{
                //printf("==%c %c, %d %d\n", s1[i - 1], s2[j - 1], i, j);
                arr[i][j] = min(min(arr[i-1][j] + 1, arr[i][j-1] + 1), arr[i-1][j-1]);
            }
        }
    }
    printarr(n1, n2, arr);
    
    int i = n1 - 1, j = n2 - 1;
    while(i > 0 || j > 0){
        if(i == 0){
            printf("insert %c at: %d\n", s2[j - 1], i);
            j--;
        }
        else if(j == 0){
            printf("delete %c at: %d\n", s1[i - 1], i);
            i--;
        }
        else if(arr[i][j] - arr[i - 1][j] == 1){
            printf("delete %c at: %d\n", s1[i -1 ], i);
            i--;
        }
        else if(arr[i][j] - arr[i][j - 1] == 1){
            printf("insert %c at: %d\n", s2[j - 1], i);
            j--;
        }
        else{
            i--;
            j--;
        }
    }
    return 0;
}