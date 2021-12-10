#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    if(s == "Mon"){
        cout << 1;
    }
    else if(s == "Tue"){
        cout << 2;
    }
    else if(s == "Wed"){
        cout << 3;
    }
    else if(s == "Thu"){
        cout << 4;
    }
    else if(s == "Fri"){
        cout << 5;
    }
    else if(s == "Sat"){
        cout << 6;
    }
    else{
        cout << 7;
    }
}