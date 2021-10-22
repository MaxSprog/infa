#include <iostream>

using namespace std;

int main(){
    int n, S;
    cin >> n >> S;
    int* arr = new int[n];
    cin >> arr[0];
    for(int i = 1; i < n; i++){
        cin >> arr[i];
        arr[i] += arr[i-1];
    }
    int c = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == S)
            c++;
    }
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(arr[j]-arr[i] == S)
                c++;
        }
    }
    cout << c;
}