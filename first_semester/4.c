#include<stdio.h>
#include <math.h>

int main()
{
    int N = 0;
    scanf("%d", &N);
    for(int i = 2; i <= sqrt(N); i++){
        if(N % i == 0){
            if(i == N/i){
                printf("%d ", i);
            }
            else{
                printf("%d %d ", i, N/i);
            }
        }
    }
    return 0;
}
