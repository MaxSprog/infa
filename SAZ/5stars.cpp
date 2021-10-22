#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> dots(n);
    unordered_map<double, int> tgs;
    for(int i = 0; i < n; i++){
        cin >> dots[i].first >> dots[i].second;
    }
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            // if(i == j) continue;
            // double c = (dots[i].first * dots[j].second - dots[j].first * dots[i].second) / (dots[i].first - dots[j].first);
            // cout << atan2(dots[i].second - dots[j].second, dots[i].first - dots[j].first) << " ";
            tgs[atan2(dots[i].second - dots[j].second, dots[i].first - dots[j].first)]++;
        }
        // cout << endl;
    }
    int M = 0;
    for(const auto& e : tgs){
        M = e.second > M ? e.second : M;
    }
    cout << M;
}