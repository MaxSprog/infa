#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main(){
    int q, n, k;
    cin >> q;
    vector<vector<double>> arr(1, vector<double>(1, 1));
    for(int p = 0; p < q; p++){
        cin >> n >> k;
        if(n == k || !k){
            printf("1\n");
            continue;
        }
        if(n < arr.size()){
            printf("%0.10g\n", arr[n][k]);
            continue;
        }
        int sz = arr.size();
        for(int i = sz; i <= n; i++){
            // cout << i << " " << n-sz+1 << endl;
            arr.push_back(vector<double>(i+1));
            arr[i][0] = 1; arr[i][i] = 1;
            for(int j = 1; j < i; j++){
                arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
            }
        }
        // for(auto e : arr){
        //     for(auto l : e){
        //         cout << l << " ";
        //     }
        //     cout << endl;
        // }
        printf("%0.10g\n", arr[n][k]);
    }
}