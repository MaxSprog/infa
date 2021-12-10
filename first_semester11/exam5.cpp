#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> arr;
    int a;
    while(cin >> a){
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    for(int i = 0; i < arr.size()-2; i++){
        if((arr[i+1] - arr[i]) != (arr[i+2] - arr[i+1])){
            cout << "NO";
            return 0;
        }
    }
    cout << arr[1] - arr[0];
}