//инверсионные пары; на вход подаются длина перестановки и элементы таблицы инверсии

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n = 0;
    scanf("%d", &n);
    int* arr = calloc(n, sizeof(int));
    int* res = calloc(n, sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int j = 0, m = 0;
    for(int i = 0; i < n; i++){
        m = arr[i] + 1;
        for(j = 0; m > 0; j++){
            if(res[j] == 0){
                m--;
            }
        }
        res[j-1] = i + 1;
    }
    for(int i = 0; i < n; i++){
        printf("%d", res[i]);
    }
    printf("\n");
    return 0;
}