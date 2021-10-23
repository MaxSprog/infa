#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int S, N;
    cin >> S >> N;
    vector<int> arr(N);
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int p = arr[0], i = 1;
    for(; i < N; i++){
        p += arr[i];
        if(p > S){
            cout << i << " " << arr[i];
            return 0;
        }
    }
}