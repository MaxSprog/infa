#include <stdio.h>
#include <stdlib.h>

int leap(int y){
    if(y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
        return 1;
    return 0;
}


int main(){
    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int d1, d2, m1, m2, y1, y2;
    scanf("%d %d %d %d %d %d", &d1, &m1, &y1, &d2, &m2, &y2);
    int res = 0;
    for(int i = y1 + 1; i < y2; i++){
        res += 365 + leap(i);
    }
    if(y1 != y2){
        for(int i = m1; i < 11 + m2; i++){
            res += months[i % 12];
        }
    }
    else{
        for(int i = m1; i < m2 - 1; i++){
            res += months[i];
        }
    }
    if(m1 != m2 || y1 != y2){
        res += months[m1 - 1] + leap(y1) * (m1 == 2) - d1;
        res += leap(y2) * (m2 == 2) + d2;
    }
    else{
        res += d2 - d1;
    }
    printf("%d", res);
    return 0;
}