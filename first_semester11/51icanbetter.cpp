#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;
    if(s[s.length()-2] == 'e'){
        cout << s.substr(0, s.length()-1) << 'r';
    }
    else if(s[s.length()-2] == 'r' && s[s.length()-3] == 'e'){
        cout << s.substr(0, s.length()-2) << "st";
    }
    else{
        cout << s.substr(0, s.length()-1) << "er";
    }
}