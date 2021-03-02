#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

void printstr(vector<string> arr){
    for(int i = 0; i < arr.size(); i++){
        cout << i + 2 << ": "<< arr[i] << endl;
    }
}

int main(){
    ifstream f("in.txt");
    int n = 0, m = 0;
    f >> n;
    vector<string> phn;
    string s;
    while(f >> s && s != "-"){
        phn.push_back(s);
    }
    printstr(phn);

    string num;
    string name;
    f >> name;
    f >> num;
    vector<vector<int>> M(name.length() + 1);
    for(int i = 0; i < name.length() + 1; i++){
        M[i].resize(num.length() + 1);
        M[i][0] = i;
    }
    for(int i = 1; i < num.length() + 1; i++){
        M[0][i] = i;
    }
    for(int i = 1; i < name.length() + 1; i++){
        for(int j = 1; j < num.length() + 1; j++){
            //cout << stoi(string(1, num[j - 1])) - 2 << " " << name[i-1] << " " << phn[stoi(string(1, num[j - 1])) - 2] << endl;
            if(phn[stoi(string(1, num[j - 1])) - 2].find(name[i-1]) == string::npos){
                M[i][j] = min(M[i-1][j] + 1, M[i][j-1] + 1);
            }
            else{
                M[i][j] = min(min(M[i-1][j] + 1, M[i][j-1] + 1), M[i-1][j-1]);
            }
        }
    }
    for(int i = 0; i < M.size(); i++){
        for(int j = 0; j < M[0].size(); j++){
            cout << M[i][j];
        }
        cout << "\n";
    }
    int i = name.length(), j = num.length();
    string res = name;
    while(i > 0 || j > 0){
        if(i == 0){
            //cout << "ins: " << i << endl;
            res.insert(i, 1, num[j - 1]);
            j--;
        }
        else if(j == 0){
            //cout << "del: " << i << endl;
            res.erase(i-1, 1);
            i--;
        }
        else if(M[i][j] - M[i][j - 1] == 1){
            //cout << "ins: " << i << endl;
            res.insert(i, 1, num[j - 1]);
            j--;
        }
        else if(M[i][j] - M[i - 1][j] == 1){
            //cout << "del: " << i << endl;
            res.erase(i-1, 1);
            i--;
        }
        
        else{
            i--;
            j--;
        }
        //cout << res << endl;
    }
    cout << res;
}