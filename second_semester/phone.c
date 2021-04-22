#include <stdio.h>
#include <stdlib.h>
#include <math.h>

size_t strlen(const char *str){
    size_t i = 0;
    while(str[i++] != '\0'){}
    return i - 1;
}

int min(int a, int b){
    return a > b ? b : a;
}
/*
char ind(char* str, int I){
    int i = 0;
    while(i++ < I){
        str++;
    }
    return *str;
}*/

int cmp(char* a, char b){
    char *buf = a;
    while(*buf != '\0'){
        if(*buf == b){
            return 0;
        }
        buf++;
    }
    return 1;
}

void printarr(int n, int m, int** arr){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void printstr(int n, int* ms, char** arr){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < ms[i]; j++){
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
}

int floor_own(double a)
{
    int temp = (int)a;
    if (temp < a/10) return temp + 1;
    return temp;
}

int main(){
    FILE* f = fopen("in.txt", "r");
    int n = 0, m = 0;
    fscanf(f, "%d", &n);
    //printf("n: %d\n", n);
    char** phn = (char**)malloc(n * sizeof(char*));
    int* ms = (int*)calloc(n, sizeof(int));
    for(int i = 0; i < n; i++){
        fscanf(f, "%d", &m);
        phn[i] = (char*)malloc(m * sizeof(char));
        ms[i] = m;
        for(int j = 0; j < m; j++){
            fscanf(f, "%c", &phn[i][j]);
        }
    }
    printstr(n, ms, phn);

    int N1 = 0, N2 = 0, buf = 0;
    fscanf(f, "%d", &N1);
    char* name = malloc(sizeof(char) * N1);
    char b;
    for(int i = 0; i < N1; i++){
        fscanf(f, "%c", &b);
        if(b != '\n' && b != ' '){
            name[i] = b;
        }
        else{
            i--;
        }
    }
    //fscanf(f, "%s", &name);
    for(int i = 0; i < N1; i++){
        printf("%c\n", name[i]);
    }
    fscanf(f, "%d", &N2);
    fscanf(f, "%d", &buf);
    int* num = (int*)calloc(N2, sizeof(int));
    int** M = (int**)malloc((N1+1) * sizeof(int*));
    for(int i = 0; i < N1+1; i++){
        M[i] = (int*)calloc(N2+1, sizeof(int));
    }
    for(int i = 0; i < N1+1; i++){
        M[i][0] = i;
    }
    printf("%d\n", buf);
    for(int i = 0; i < N2; i++){
        M[0][i] = i;
        printf("%d %d %d\n", buf, floor_own(pow(10, N2 - i)), floor_own(pow(10, N2 - i - 1)));
        num[i] = buf % floor_own(pow(10, N2 - i)) / floor_own(pow(10, N2 - i - 1));
    }
    M[0][N2] = N2;
    for(int i = 0; i < N2; i++){
        printf("%d", num[i]);
    }
    printf("\n");
    for(int i = 1; i < N1+1; i++){
        for(int j = 1; j < N2+1; j++){
            printf("%s %c\n", phn[num[j - 1] - 2], name[i-1]);
            if(cmp(phn[num[j - 1] - 2], name[i-1])){
                //printf("!=%c %c, %d %d\n", s1[i - 1], s2[j - 1], i, j);
                M[i][j] = min(M[i-1][j] + 1, M[i][j-1] + 1);
            }
            else{
                //printf("==%c %c, %d %d\n", s1[i - 1], s2[j - 1], i, j);
                M[i][j] = min(min(M[i-1][j] + 1, M[i][j-1] + 1), M[i-1][j-1]);
            }
        }
    }
    printarr(N1 + 1, N2 + 1, M);
    int i = N1, j = N2;
    while(i > 0 || j > 0){
        if(i == 0){
            printf("insert %d at: %d\n", num[j - 1], i-1);
            j--;
        }
        else if(j == 0){
            printf("delete %c at: %d\n", name[i - 1], i-1);
            i--;
        }
        else if(M[i][j] - M[i - 1][j] == 1){
            printf("delete %c at: %d\n", name[i - 1], i-1);
            i--;
        }
        else if(M[i][j] - M[i][j - 1] == 1){
            printf("insert %d at: %d\n", num[j - 1], i-1);
            j--;
        }
        else{
            i--;
            j--;
        }
    }
    return 0;
}