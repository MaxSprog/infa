#include <iostream>

using namespace std;

int max(int n, int* arr){
    int M = arr[0];
    for(int i = 1; i < n; i++){
        M = M < arr[i] ? arr[i] : M;
    }
    return M;
}

int count(int N, int* lvl, int** adj, int i){
    if(lvl[i] != -1)
        return lvl[i];
    int M = adj[i][0] == -1 ? count(N, lvl, adj, 0) : adj[i][0] + 1;
    adj[i][0] = M - 1;
    for(int j = 1; j < N; j++){
        if(adj[i][j] == -1){
            adj[i][j] = count(N, lvl, adj, j);
        }
        M = M < adj[i][j] + 1 ? adj[i][j] + 1 : M;
    }
    lvl[i] = M;
    return M;
}

int main(){
    int N, M;
    cin >> N >> M;
    int** adj = new int*[N];
    int* lvl = new int[N];
    for(int i = 0; i < N; i++){
        lvl[i] = -1;
        adj[i] = new int[N];
        for(int j = 0; j < N; j++){
            adj[i][j] = 0;
        }
    }
    for(int i = 0; i < N; i++){
        int ki;
        cin >> ki;
        if(ki == 0){
            lvl[i] = 0;
            continue;
        }
        int b;
        for(int j = 0; j < ki; j++){
            cin >> b;
            adj[i][--b] = -1;
        }
    }
    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < N; j++){
    //         cout << adj[i][j];
    //     }
    //     cout << endl;
    // }
    for(int i = 0; i < N; i++){
        lvl[i] = count(N, lvl, adj, i);
    }
    for(int i = 0; i < N; i++){
        if(lvl[i] == M)
            cout << i + 1 << " ";
        // cout << "cringe: " << lvl[i] << " ";
    }
}