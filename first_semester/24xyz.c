#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE* fin = fopen("in24.txt", "r");
    int n, res = 0, Mx = 0, flag = 0;
    char c1, c2;
    fscanf(fin, "%d", &n);
    //char* in = malloc(n * sizeof(char));
    fscanf(fin, "%c", &c1);
    fscanf(fin, "%c", &c1);
    for(int i = 1; i < n; i++){
        fscanf(fin, "%c", &c2);
        //printf("%c %c\n", c1, c2);
        if(c1 != c2){
            if(flag){
                res++;
            }
            else{
                res = 1;
                flag = 1;
            }
        }
        else{
            flag = 0;
            Mx = res > Mx ? res : Mx;
        }
        c1 = c2;
    }
    fclose(fin);
    Mx = res > Mx ? res : Mx;
    printf("%d", Mx);
    return 0;
}