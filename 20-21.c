#include<stdio.h>

void to_Ticket(int n){
    int x = n, i = 0;
    while(x > 0){
        x /= 10;
        i++;
    }
    i = 6 - i;
    for(; i > 0; i--){printf("0");}
    printf("%d\n", n);
}

void OneCycle(){
    //int j = 0;
    for(int i = 0; i < 1000000; i++){
        if(i / 100000 + i / 10000 % 10 + i / 1000 % 10 == i / 100 % 10 + i / 10 % 10 + i % 10){
            to_Ticket(i);
            //j++;
        }
    }
    //printf("Количество: %d", j);
}

void SixCycles(){
    //int k = 0;
    for(int i = 0; i <= 9; i++){
        for(int j = 0; j <= 9; j++){
            for(int l = 0; l <= 9; l++){
                for(int x = 0; x <= 9; x++){
                    for(int y = 0; y <= 9; y++){
                        for(int z = 0; z <= 9; z++){
                            if(i + j + l == x + y + z){
                                to_Ticket(i * 100000 + j * 10000 + l * 1000 + x * 100 + y * 10 + z);
                                //k++;
                            }
                        }
                    }
                }
            }
        }
    }
    //printf("Количество: %d", k);
}

int main()
{
    OneCycle();
    //SixCycles();
    return 0;
}