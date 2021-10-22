#include <stdio.h>

struct dateStruct{
    int d, m, y;
};

int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int leapYears(struct dateStruct d){
    int years = d.y;

    if (d.m <= 2)
        years--;

    return years / 4 - years / 100 + years / 400;
}

int dif(struct dateStruct d1, struct dateStruct d2){
    long int n1 = d1.y*365 + d1.d;

    for (int i=0; i<d1.m - 1; i++)
        n1 += monthDays[i];

    n1 += leapYears(d1);

    long int n2 = d2.y*365 + d2.d;
    for (int i=0; i<d2.m - 1; i++)
        n2 += monthDays[i];
    n2 += leapYears(d2);

    return (n2 - n1);
}

int main(){
    struct dateStruct d1, d2;
    scanf("%d %d %d %d %d %d", &d1.d, &d1.m, &d1.y, &d2.d, &d2.m, &d2.y);
    printf("%d\n", dif(d1, d2));

    return 0;
}