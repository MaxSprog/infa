#include <iostream>
#include <string>

using namespace std;

template <class T>
class Stack{
    private:
        struct list {
            T data;
            struct list * next;
        };
        typedef struct stack {struct list *top;} stck;
        stck *S;

    public:
        Stack(){
            S = new stck;
            S->top = NULL;
        }
        ~Stack(){
            struct list *p;
            while (S->top){
                p = S->top;
                S->top = p->next;
                delete[] p;
            }
            delete[] S;
        }
        void makenull(){
            struct list *p;
            while (S->top){
                p = S->top;
                S->top = p->next;
                delete[] p;
            }
        }
        T top(){//return S->top ? (S->top->data) : 0;
            if(S->top != NULL)
                return S->top->data;
            return 0;
        }
        T pop(){
	        T a;
	        struct list *p;
	        p = S->top;
	        a = p->data;
	        S->top = p->next;
	        delete[] p;
	        return a;
        }
        void push(T a){
	        struct list *p;
	        p = new struct list;
	        p->data = a;
	        p->next = S->top;
	        S->top = p;
        }
        bool empty(){return S->top == NULL;}
};

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