#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;
    if(((s[s.length()-3] - '0') * 10 + (s[s.length()-2] - '0')) % 5 == 0){
        int c = 0;
        for(int i = 0; i < s.length()-1; i++){
            c += s[i] - '0';
        }
        if(c % 3 == 0){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}