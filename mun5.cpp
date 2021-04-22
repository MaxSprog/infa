#include <iostream>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

int min(vector<vector<int>> arr, int i)
{
    int m = arr[0][i];
    for (int j = 1; j < arr.size(); j++)
    {
        m = arr[j][i] < m ? arr[j][i] : m;
    }
    return m;
}

int max(map<vector<double>, vector<int>> arr)
{
    int M = 0;
    for (map<vector<double>, vector<int>>::iterator it = arr.begin(); it != arr.end(); it++)
    {
        M = it->second[0] > M ? it->second[0] : M;
    }
    return M;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> crds(n);
    for (int i = 0; i < n; i++)
    {
        crds[i].resize(2);
        cin >> crds[i][0] >> crds[i][1];
    }
    /*
    int minx = min(crds, 0), miny = min(crds, 1);
    //cout << "min: " << minx << " " << miny << endl;
    if (minx <= 0)
    {
        int d = 1 - minx;
        for (int i = 0; i < n; i++)
        {
            crds[i][0] += d;
        }
    }
    if (miny <= 0)
    {
        int d = 1 - miny;
        for (int i = 0; i < n; i++)
        {
            crds[i][1] += d;
        }
    }
    // cout << "--------" << endl;
    // for(int i = 0; i < crds.size(); i++){
    //     for(int j = 0; j < crds[i].size(); j++){
    //         cout << crds[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << "ok" << endl;
    */
    map<vector<double>, vector<int>> lns;

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(i == j) continue;
            vector<double> arr(2);
            if(crds[i][1] - crds[j][1] == 0){
                arr = {10001, (double)(crds[i][0] * crds[j][1] - crds[j][0] * crds[i][1]) / (double)(crds[i][0] - crds[j][0])};
            }
            else if(crds[i][0] - crds[j][0] == 0){
                arr = {(double)abs(crds[i][0] - crds[j][0]) / (double)abs(crds[i][1] - crds[j][1]), 10001};
            }
            else{
                arr = {(double)abs(crds[i][0] - crds[j][0]) / (double)abs(crds[i][1] - crds[j][1]), (double)(crds[i][0] * crds[j][1] - crds[j][0] * crds[i][1]) / (double)(crds[i][0] - crds[j][0])};
            }
            // cout << "dots: " << crds[i][0] << ", " << crds[i][1] << " | " << crds[j][0] << ", " << crds[j][1] << endl; 
            // cout << "ctg & y: " << arr[0] << " " << arr[1] << endl;
            // cout << "exists: " << lns.count(arr) << endl;
            if (lns.count(arr) == 0)
            {
                // cout << "new!\n";
                lns[arr] = {2, i};
            }
            else if(lns[arr][1] == i)
            {
                lns[arr][0]++;
                // cout << "+1 " << lns[arr][0] << endl;
            }
        }
    }
    // cout << "????\n";
    cout << max(lns);
}