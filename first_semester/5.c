#include<stdio.h>
#include <math.h>

int main()
{
    int N = 0, flag = 0;
    scanf("%d", &N);
    for(int i = 2; i <= N; i++){
        for(int j = 2; j <= sqrt(i); j++){
            if(i % j == 0){
                flag = 1;
                break;
            }
        }
        if(!flag)
            printf("%d ", i);
        flag = 0;
    }
    return 0;
}