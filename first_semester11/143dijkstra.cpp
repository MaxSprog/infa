#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main(){
    int n, s, e;
    cin >> n >> s >> e;
    s--; e--;
    vector<vector<int>> adj(n, vector<int>(n, SHRT_MAX));
    vector<bool> seen(n, false);
    vector<int> dist(n, SHRT_MAX);
    int a, b, k;
    for(; cin >> a;){
        cin >> b >> k;
        adj[a-1][b-1] = k;
        adj[b-1][a-1] = k;
    }
    dist[s] = 0;
    int curr = s;
    while(curr != -1){
        for(int i = 0; i < n; i++){
            if(dist[i] > dist[curr] + adj[curr][i]){
                dist[i] = dist[curr] + adj[curr][i];
            }
        }
        seen[curr] = true;
        if(seen[e]){
            cout << dist[e];
            return 0;
        }
        curr = -1;
        int min = SHRT_MAX;
        for(int i = 0; i < n; i++){
            if(dist[i] < min && !seen[i]){
                min = dist[i];
                curr = i;
            }
        }
    }
    cout << "no";
}