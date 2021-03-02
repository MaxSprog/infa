#include <stdio.h>

void erat(int n){
    int a[n+1];
    for (int i = 0; i <= n; i++)
        a[i] = 1;

    for (int i = 2; i*i <= n; i++){
        if (a[i]){
            int j = 0, k = 0;
            for (int j = i*i; j<=n; j+=i)
                a[j] = 0;            
        }
    }
    for (int i = 2; i < n; i++){
        if (a[i]){
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main(){
    int n;
    scanf("%d", &n);
    erat(n);
}
