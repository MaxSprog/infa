#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;
    if(s.length() == 4 && s[1] == 'A'){
        cout << "FITS";
    }
    else{
        cout << "DOES NOT FIT";
    }
}