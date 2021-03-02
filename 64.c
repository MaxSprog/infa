#include<stdio.h>
#include <stdlib.h>

int main(){
    FILE *f1 = fopen("in.txt", "r");
    FILE *f2 = fopen("out.txt", "w");
    int n = 0, k = 0;
    fscanf(f1, "%d %d", &n, &k);
    if(n < 0 || k < 0 || k > n){
        fprintf(f2, "No");
        return 0;
    }
    if(n == k){
        fprintf(f2, "1");
        return 0;
    }
    unsigned long long** tri = (unsigned long long**)malloc(sizeof(unsigned long long*) * (n+1));
    for(int i = 1; i <= n + 1; i++){
        tri[i - 1] = (unsigned long long*)malloc(sizeof(unsigned long long) * i);
    }
    tri[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0 || j == i){
                tri[i][j] = 1;
            }
            else{
                tri[i][j] = tri[i - 1][j - 1] + tri[i - 1][j];
            }
        }
    }
    fprintf(f2, "%llu", tri[n][k]);
    for(int i = 0; i <= n; i++){
        free(tri[i]);
    }
    free(tri);
    fclose(f1);
    fclose(f2);
    return 0;
}