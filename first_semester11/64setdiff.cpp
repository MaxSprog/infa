#include <iostream>
#include <string>

using namespace std;

int main(){
    string S1, S2;
    cin >> S1 >> S2;
    int let[26] = {};
    for(int i = 0; i < S1.length(); i++){
        let[S1[i] - 'A']++;
    }
    for(int i = 0; i < S2.length(); i++){
        if(let[S2[i] - 'A']) let[S2[i] - 'A']++;
    }
    bool empty = true;
    for(int i = 0; i < 26; i++){
        if(let[i] == 1){
            empty = false;
            cout << (char)('A' + i);
        }
    }
    if(empty)
        cout << "Empty Set";
}