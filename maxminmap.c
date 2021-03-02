#include <stdio.h>
#include <stdlib.h>

void printarr(int n, int m, int** arr){
    FILE* out = fopen("out.txt", "w");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            fprintf(out, "%d ", arr[i][j]);
        }
        fprintf(out, "\n");
    }
    fclose(out);
}

int main(){
    FILE *f = fopen("in.txt", "r");
    int n = 0, m = 0;
    fscanf(f, "%d %d", &n, &m);
    int** map = malloc(n * sizeof(int*));
    int** M = malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++){
        map[i] = calloc(m, sizeof(int));
        M[i] = calloc(m, sizeof(int));
        for(int j = 0; j < m; j++){
            fscanf(f, "%d", &map[i][j]);
            M[i][j] = map[i][j];
        }
    }
    fclose(f);
    for(int i = 1; i < m; i++){
        M[0][i] += M[0][i-1];
    }
    for(int i = 1; i < n; i++){
        M[i][0] += M[i-1][0];
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(M[i-1][j] > M[i][j - 1]){
                M[i][j] = M[i][j] + M[i-1][j];
            }
            else{
                M[i][j] = M[i][j] + M[i][j-1];
            }
        }
    }
    printarr(n, m, M);
    return 0;
}