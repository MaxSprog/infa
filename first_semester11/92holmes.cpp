#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;
    n *= 2;
    bool** arr = new bool*[n];
    bool** arr2 = new bool*[n];
    string* s = new string[n];
    for(int i = 0; i < n; i++){
        arr[i] = new bool[n];
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        cin >> s[i]; 
    }
    
}