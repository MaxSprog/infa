#include <iostream>
// #include <cstddef>

using namespace std;

struct list {
    int data;
    struct list * next;
};

class List{
    private:
        struct list *head;
    public:
        List(){
            head = new struct list;
            head = NULL;
        }
        ~List(){
            struct list* temp;
            while(head){
                temp = head;
                head = temp->next;
                delete[] temp;
            }
            delete[] head;
        }
        void makenull(){
            struct list *temp;
            while (head){
                temp = head;
                head = temp->next;
                delete[] temp;
            }
        }
        int length(){
            int cnt = 0;
            struct list *temp = head;
            while(temp){
                temp = temp->next;
                cnt++;
            }
            return cnt;
        }
        void print(){
            struct list *temp = head;
            while(temp){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        void deleteElement(int data){
            struct list *temp = head;
            if (temp->data == data){
                head = temp->next;
                delete[] temp;
                return;
            }
            while(temp->next->data != data && temp->next->next){
                temp = temp->next;
            }
            if(!temp->next)
                return;
            struct list *nxtemp = temp->next->next;
            delete[] temp->next;
            temp->next = nxtemp;
        }
        void insert(int data, int ind){//-1 --- в конец списка
            int n = length();
            if(ind > n){
                ind = n;
            }
            if(ind < 0 || !head){
                if(ind == -1 && head){
                    ind = n;
                }
                else{
                    ind = 0;
                }
            }
            if(ind < n || !n){
                if(ind == 0){
                    struct list *h = new struct list;
                    h->data = data;
                    h->next = head;
                    head = h;
                    return;
                }
                else{
                    struct list *temp, *lt, *rt;
                    rt = head;
                    for (int i = 0; i < ind; i++){
                        lt=rt;
                        rt=rt->next;
                    }
                    temp = new struct list;
                    temp->data = data;
                    lt->next = temp;
                    lt = temp;
                    lt->next = rt;
                    return;
                }
            }
            struct list *temp = head;
            struct list *h = new struct list;
            
            h->data = data;
            h->next = NULL;
            for(int i = 0; i < ind && temp->next; i++)
                temp = temp->next;
            temp->next = h;
        }
};

class Stack{
    private:
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
        int top(){
            return S->top->data;
        }
        int pop(){
            int a;
            struct list *p;
            p = S->top;
            a = p->data;
            S->top = p->next;
            delete[] p;
            return a;
        }
        void push(int a){
            struct list *p;
            p = new struct list;
            p->data = a;
            p->next = S->top;
            S->top = p;
        }
        bool empty(){
            return !S->top;
        }
};

int main(){
    Stack s1, s2;
    List l;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int p;
        cin >> p;
        s1.push(p);
    }
    for(int i = 0; i < m; i++){
        int p;
        cin >> p;
        s2.push(p);
    }
    for(int i = 0; i < n + m; i++){
        if(s1.empty())
            l.insert(s2.pop(), -1);
        else if(s2.empty())
            l.insert(s1.pop(), -1);
        else
            l.insert(s1.top() > s2.top() ? s1.pop() : s2.pop(), -1);
    }
    l.print();
}