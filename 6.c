#include<stdio.h>

int main()
{
    int N = 0, flag = 0;
    scanf("%d", &N);
    for(int i = 2; i * 2 <= N; i++){
        if(N % i == 0){
            for(int j = 2; j * j <= i; j++){
                if(i % j == 0){
                    flag = 1;
                    break;
                }
            }
            if(!flag)
                printf("%d ", i);
            flag = 0;
        }
    }
    return 0;
}
