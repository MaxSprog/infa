#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    // for(int i = 0; i < n-1; i++){
    //     for(int j = i; j < n-i-1; j++){
    //         if(arr[j+1] < arr[j]){
    //             swap(arr[j+1], arr[j]);
    //         }
    //     }

    //     for(int j = n-i-1; j >= i; j--){
    //         if(arr[j+1] < arr[j]){
    //             swap(arr[j+1], arr[j]);
    //         }
    //     }
    // }
    bool swapped;
    do{
        swapped = false;
        for(int i = 0; i < n-2; i++){
            if(arr[i] > arr[i+1]){
                swap(arr[i+1], arr[i]);
                swapped = true;
            }
        }
        if(!swapped)
            break;
        swapped = false;
        for(int i = n-2; i >= 0; i--){
            if(arr[i] > arr[i+1]){
                swap(arr[i+1], arr[i]);
                swapped = true;
            }
        }
    }while(swapped);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}