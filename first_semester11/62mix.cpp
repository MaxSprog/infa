#include <iostream>
#include <string>

using namespace std;

int main(){
    string s, cols;
    bool R = false, Y = false, B = false;
    cin >> s;
    if(s == "purple"){
        R = true;
        B = true;
    }
    else if(s == "orange"){
        R = true;
        Y = true;
    }
    else{
        Y = true;
        B = true;
    }
    cin >> cols;
    for(int i = 0; i < cols.length(); i++){
        if(cols[i] == 'R' && R){
            R = false;
            cout << i + 1 << " ";
        }
        else if(cols[i] == 'Y' && Y){
            Y = false;
            cout << i + 1 << " ";
        }
        else if(cols[i] == 'B' && B){
            B = false;
            cout << i + 1 << " ";
        }
        if(!R && !Y && !B){
            break;
        }
    }
}