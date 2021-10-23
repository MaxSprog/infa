#include <iostream>
#include <string>
#include <cmath>
#include <stack>

using namespace std;

int main(){
    int a, b, dec = 0;
    cin >> a >> b;
    string s;
    stack<int> fin;
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        dec += (s[i] - '0') * (int)pow(a, s.length() - i - 1);
    }
    if(b != 10){
        for(; dec; dec /= b){
            fin.push(dec % b);
        }
        while(!fin.empty()){
            char c;
            if(fin.top() > 9){
                c = (char)('A' + fin.top() - 10);
                cout << c;
            }
            else{
                cout << fin.top();
            }
            fin.pop();
        }
    }
    else{
        cout << dec;
    }
}