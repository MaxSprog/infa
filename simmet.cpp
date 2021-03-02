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

int issim(int n, int* arr){
    int m = 1;
    int** nums = malloc(sizeof(int*));
    nums[0] = calloc(2, sizeof(int));
    for(int i = 0; i < n / 2; i++){
        for(int j = 0; j < m; j++){
            
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
        count += issim(n, arr);
    }
    cout << count;
    return 0;
}