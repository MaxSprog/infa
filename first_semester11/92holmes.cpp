#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    n *= 2;
    vector<vector<int>> arr(n, vector<int>(n, 0));
    vector<vector<int>> arr2(n, vector<int>(n, 0));
    vector<string> s(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            if(arr[i][j]){
                if(arr[j][n-i-1] || arr[n-j-1][i] || arr[n-i-1][n-j-1]){
                    cout << "No";
                    return 0;
                }
            }
            arr2[i][j] = arr[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j]){
                cout << s[i][j];
            }
        }
    }
    //first turn
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            arr2[i][j] = arr[n-j-1][i];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr2[i][j]){
                cout << s[i][j];
            }
        }
    }
    //second turn
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            arr[i][j] = arr2[n-j-1][i];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j]){
                cout << s[i][j];
            }
        }
    }
    //third turn
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            arr2[i][j] = arr[n-j-1][i];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr2[i][j]){
                cout << s[i][j];
            }
        }
    }
}