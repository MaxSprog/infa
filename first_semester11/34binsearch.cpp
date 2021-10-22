#include <iostream>

using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    int* arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int i = n / 2 - (n + 1) % 2;
    while(true){
        if(arr[i] == x){
            cout << i;
            break;
        }
        if(n < 1){
            cout << -1;
            break;
        }
        n /= 2;
        if(x > arr[i]){
            i += n / 2 + (n/2 == 0);
        }
        else if(x < arr[i]){
            i -= n / 2 + (n/2 == 0);
        }
    }
}