#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


void printarr(int n, int m, int** arr){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main(){
    string s1 = "123";
    string s2 = "231";
    int n1 = s1.length() + 1;
    int n2 = s2.length() + 1;
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
    printarr(n1, n2, arr);
    for(int i = 1; i <= n1; i++){
        for(int j = 1; j <= n2; j++){
            if(s1[i] != s2[j]){
                arr[i][j] = min(arr[i-1][j] + 1, arr[i][j-1] + 1);
            }
            else{
                arr[i][j] = min(min(arr[i-1][j] + 1, arr[i][j-1] + 1), arr[i-1][j-1]);
            }
        }
    }
    printarr(n1, n2, arr);
    /*
    int i = n1 - 1, j = n2 - 1;
    while(i > 0 || j > 0){
        if(M[i][j] )
    }*/
}