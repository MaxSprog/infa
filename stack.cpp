#include <iostream>
#include <string>
#include "StackClass.cpp"

using namespace std;

int prior(char a){
    if(a == '(') return 1;
    if(a == ')') return 2;
    if(a == '=') return 3;
    if(a == '+' || a == '-') return 4;
    if(a == '*' || a == '/') return 5;
    return 0;
}

int main(){
    string lin, lout;
    Stack<char> S;
    cin >> lin;
    for(int i = 0; i < lin.length(); i++){
        if(!prior(lin[i])){
            lout.push_back(lin[i]);
        }
        else if(lin[i] == '('){
            S.push('(');
        }
        else if(lin[i] == ')'){
            while(S.top() != '('){
                lout.push_back(S.pop());
            }
            S.pop();
        }
        else{
            while(!S.empty() && prior(S.top()) >= prior(lin[i])){
                lout.push_back(S.pop());
            }
            S.push(lin[i]);
        }
    }
    while(!S.empty()){
        lout.push_back(S.pop());
    }
    cout << lout;
}