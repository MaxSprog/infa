#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE* fin = fopen("crossword.txt", "r");
    int n, m;
    fscanf(fin, "%d %d", &n, &m);
    int** arr = malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++){
        arr[i] = calloc(m, sizeof(int));
        for(int j = 0; j < m; j++){
            fscanf(fin, "%d", &arr[i][j]);
        }
    }
    int c = 0;
    printf("Raws:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 1){
                c++;
            }
            if(c != 0 && (arr[i][j] == 0 || j + 1 == m)){
                printf("%d ", c);
                c = 0;
            }
        }
        printf("\n");
    }
    c = 0;
    printf("Columns:\n");
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(arr[j][i] == 1){
                c++;
            }
            if(c != 0 && (arr[j][i] == 0 || j + 1 == n)){
                printf("%d ", c);
                c = 0;
            }
        }
        printf("\n");
    }
    return 0;
}