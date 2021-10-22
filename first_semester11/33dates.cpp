#include <iostream>

using namespace std;

struct dateStruct{
    int d, m, y;
};

int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int isLeap(int y){
    if(y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
        return 1;
    return 0;
}

int leapYears(struct dateStruct d){
    int years = d.y;

    if (d.m <= 2)
        years--;

    return years / 4 - years / 100 + years / 400;
}

int Abs(int a){
    return a < 0 ? -1*a : a;
}

int dif(struct dateStruct d1, struct dateStruct d2){
    long int n1 = d1.y * 365 + d1.d;

    for (int i=0; i < d1.m - 1; i++)
        n1 += monthDays[i];

    n1 += leapYears(d1);

    long int n2 = d2.y * 365 + d2.d;
    for (int i=0; i < d2.m - 1; i++)
        n2 += monthDays[i];
    n2 += leapYears(d2);

    return Abs(n2 - n1);
}

int main(){
    struct dateStruct d1, d2;
    cin >> d1.d >> d1.m >> d1.y >> d2.d >> d2.m >> d2.y;
    if(d1.d < 1 || d2.d < 1 || d1.m < 1 || d2.m < 1 || d1.y < 1 || d2.y < 1 || d2.y > 2012 || d1.y > 2012){
        cout << "ERROR";
        return 0;
    }
    if(d1.d > monthDays[d1.m-1] + (d1.m == 2)*isLeap(d1.y) || d1.m > 12){
        cout << "ERROR";
        return 0;
    }
    if(d2.d > monthDays[d2.m-1] + (d2.m == 2)*isLeap(d2.y) || d2.m > 12){
        cout << "ERROR";
        return 0;
    }
    cout << dif(d1, d2);
}