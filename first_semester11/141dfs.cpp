#include <iostream>
#include <vector>
using namespace std;

void dfs(int n, vector<vector<bool>>& adj, vector<int>& seen, int v, int c){
    for(int i = 0; i < n; i++){
        if(adj[v][i] && !seen[i]){
            seen[i] = c;
            dfs(n, adj, seen, i, c);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> adj(n, vector<bool>(n, false));
    vector<int> seen(n, 0);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a-1][b-1] = true;
        adj[b-1][a-1] = true;
    }
    int c = 0;
    for(int i = 0; i < n; i++){
        if(!seen[i]){
            seen[i] = ++c;
            dfs(n, adj, seen, i, c);
        }
    }
    cout << c << "\n";
    for(int i = 0; i < n; i++){
        cout << seen[i] << " ";
    }
}