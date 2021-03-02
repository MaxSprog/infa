#include <stdio.h>
#include <stdlib.h>

int main(){
    int n = 0, f1 = 1, f2 = 1, i = 0, j = 0;
    scanf("%d", &n);
    int** adj = malloc(n * sizeof(int*));
    for(i = 0; i < n; i++){
        adj[i] = calloc(n, sizeof(int));
        for(j = 0; j < n; j++){
            scanf("%d", &adj[i][j]);
        }
    }
    int* used = calloc(n, sizeof(int));
    while(1){
        for(i = 0; i < n; i++){
            f1 = 1;
            for(j = 0; j < n; j++){
                if(adj[j][i] != 0 || used[i]){
                    f1 = 0;
                    break;
                }
            }
            if(f1){
                printf("%d ", i + 1);
                for(int k = 0; k < n; k++){
                    adj[i][k] = 0;
                }
                used[i] = 1;
            }
        }
        f2 = 1;
        for(int k = 0; k < n; k++){
            if(!used[k]){
                f2 = 0;
                break;
            }
        }
        if(f2){
            return 0;
        }
    }
    return 0;
}