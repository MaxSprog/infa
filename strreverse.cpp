#include <iostream>
#include <string>

using namespace std;


void reverse(){
    char c = getchar();
    if(c == '\n'){
        cout << c;
        return;
    }
    reverse();
    cout << c;
}

int main(){
    string s = "";
    reverse();
}