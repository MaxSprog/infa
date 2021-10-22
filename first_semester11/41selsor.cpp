#include <iostream>

using namespace std;

int Min(int n, int s, int* arr){
    int min = arr[s], ind = s;
    for(int i = s+1; i < n; i++){
        if(min > arr[i]){
            min = arr[i];
            ind = i;
        }
    }
    return ind;
}

int main(){
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        swap(arr[i], arr[Min(n, i, arr)]);
    }
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}