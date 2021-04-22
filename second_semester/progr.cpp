#include <iostream>
#include <math.h>

using namespace std;

void add(int* arr){
    int i = 0;
    while(arr[i] == 9){
        arr[i++] = 0;
    }
    arr[i] += 1;
}

int isprog(int n, int* arr){
    int* copy = (int*)calloc(n, sizeof(int));
    for(int i = 0; i < n; i++){
        copy[i] = arr[i];
    }
    int d = copy[0] - copy[1];
    for(int i = 1; i < n - 1; i++){
        if(d != copy[i] - copy[i+1]){
            return 0;
        }
    }/*
    for(int i = 0; i < n; i++){
        cout << copy[i];
    }*/
    //cout << "\n";
    return 1;
}

int main(){
    int n = 0, count = 0;
    cin >> n;
    int* arr = (int*)calloc(n, sizeof(int));
    arr[n - 1] = 1;
    for(long long i = 0; i < pow(10, n) - pow(10, n - 1) - 1; i++){
        add(arr);
        count += isprog(n, arr);
    }
    cout << count;
    return 0;
}