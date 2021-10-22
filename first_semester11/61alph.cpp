#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    bool k = false;
    for(int i = 0; cin >> s; i++){
        for(int j = 0; j < s.length(); j++){
            if(s[j] - 'a' == i){
                k = true;
                break;
            }
        }
        if(k){
            k = false;
        }
        else{
            if((i + 1) % 2 == 0){
                cout << "PLAYER 1";
            }
            else{
                cout << "PLAYER 2";
            }
            return 0;
        }
    }
    cout << "NO WINNER";
}