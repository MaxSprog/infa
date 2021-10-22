#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int** arr = new int*[n];
    for(int i = 0; i < n; i++){
        arr[i] = new int[n];
        for(int j = 0; j < n; j++){
            arr[i][j] = INT_MAX;
        }
    }
    for(int i = 0; i < m; i++){
        int a, b, x;
        cin >> a >> b;
        cin >> x;
        a--; b--;
        arr[a][b] = min(arr[a][b], x);
        arr[b][a] = arr[a][b];
    }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(arr[i][k] != INT_MAX && arr[k][j] != INT_MAX)
                    if(arr[i][j] > arr[i][k] + arr[k][j])
                        arr[i][j] = arr[i][k] + arr[k][j];
    int k;
    cin >> k;
    for(int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        cout << arr[a-1][b-1] << "\n";
    }
}