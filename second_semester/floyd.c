//алгоритм Флойда; на вход подаются количество вершин и таблица смежности графа

#include <stdio.h>
#include <stdlib.h>

void printarr(int n, int m, int** arr){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int n = 0;
    scanf("%d", &n);
    int** M = malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++){
        M[i] = calloc(n, sizeof(int));
        for(int j = 0; j < n; j++){
            scanf("%d", &M[i][j]);
        }
    }
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(M[i][j] > M[i][k] + M[k][j])
                    M[i][j] = M[i][k] + M[k][j];
    printarr(n, n, M);
    return 0;
}