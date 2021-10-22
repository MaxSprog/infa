#include <iostream>
#include <string>

using namespace std;

int main(){
    string sf;
    cin >> sf;
    bool let[26] = {};
    for(int i = 0; i < sf.length(); i++){
        let[sf[i] - 'a'] = true;
    }
    string s;
    bool flag;
    for(;cin >> s;){
        flag = true;
        for(int i = 0; i < s.length(); i++){
            if(let[s[i] - 'a']){
                flag = false;
                break;
            }
        }
        if(flag) cout << s << endl;
    }
}