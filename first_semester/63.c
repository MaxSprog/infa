#include<stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int* a = malloc(sizeof(int));
    char* b = a;
    *(b) = (int)123456789 / (int)pow(2, 0);
    *(b+1) = (int)123456789 / (int)pow(2, 8);
    *(b+2) = (int)123456789 / (int)pow(2, 16);
    *(b+3) = (int)123456789 / (int)pow(2, 24);
    printf("%d\n", *a);
    printf("%d %d %d %d", (int)"7", (int)"+", (int)"8", (int)"22");
    return 0;
}