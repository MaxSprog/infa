#include <iostream>
#include <string>
#include <cstring>
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

string oper(int a, int b, char op){
    if(op == '+') return to_string(a + b);
    else if(op == '-') return to_string(b - a);
    else if(op == '*') return to_string(a * b);
    return to_string(b / a);
}

int main(){
    string lin, lout;
    Stack<char> S;
    cin >> lin;
    for(int i = 0; i < lin.length(); i++){
        if(!prior(lin[i])){
            lout.push_back(lin[i]);
            // lout.push_back(' ');
        }
        else if(lin[i] == '('){
            S.push('(');
        }
        else if(lin[i] == ')'){
            lout.push_back(' ');
            while(S.top() != '('){
                lout.push_back(S.pop());
            }
            S.pop();
        }
        else{
            lout.push_back(' ');
            while(!S.empty() && prior(S.top()) >= prior(lin[i])){
                lout.push_back(S.pop());
            }
            S.push(lin[i]);
        }
    }
    while(!S.empty()){
        lout.push_back(' ');
        lout.push_back(S.pop());
    }
    cout << lout << endl;
    S.makenull();
    
    Stack<char*> Q;
    for(int i = 0; i < lout.length(); i++){
        if(lout[i] != ' '){
            if(!prior(lout[i])){
                Q.push(&lout[i]);
            }
            else{
                string a = Q.pop();
                string b = Q.pop();
                string op = oper(stoi(a), stoi(b), lout[i]);
                char* cstr = new char[op.length() + 1];
                strcpy(cstr, op.c_str());
                Q.push(cstr);
            }
        }
    }
    cout << Q.pop() << endl;
}