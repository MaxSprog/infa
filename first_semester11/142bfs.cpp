#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> maze(n, vector<bool>(m));
    pair<int, int> start, end;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c;
            cin >> c;
            if(c == 'X'){
                maze[i][j] = false;
            }
            else{
                if(c == 'F'){
                    end = make_pair(i, j);
                }
                else if(c == 'S'){
                    start = make_pair(i, j);
                }
                maze[i][j] = true;
            }
        }
    }
    vector<pair<int, int>> itr = {make_pair(-1, 0), make_pair(0, -1), make_pair(0, 1), make_pair(1, 0)};
    queue<pair<int, int>> Q;
    vector<vector<bool>> seen(n, vector<bool>(m, false));
    vector<vector<int>> dist(n, vector<int>(m, SHRT_MAX));
    dist[start.first][start.second] = 0;
    pair<int, int> p;
    Q.push(start);
    while(!Q.empty()){
        p = Q.front();
        Q.pop();
        if(p == end)
            break;
        if(!seen[p.first][p.second]){
            seen[p.first][p.second] = true;
            for(auto e : itr){
                int i = p.first + e.first, j = p.second + e.second;
                if(i >= 0 && i < n && j >= 0 && j < m && maze[i][j] && !seen[i][j]){
                    Q.push(make_pair(i, j));
                    if(dist[i][j] > dist[p.first][p.second] + 1){
                        dist[i][j] = dist[p.first][p.second]+1; 
                    }
                }
            }
        }
    }
    if(dist[end.first][end.second] == SHRT_MAX){
        cout << -1 << endl;
    }
    else{
        cout << dist[end.first][end.second] << endl;
    }
}