#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool is_num(char c){
    return ('0' <= c && c <= '9');
}

template <class T>
class BinTree{
    private:
        typedef struct node {
            T data;
            struct node* rt;
            struct node* lt;
            struct node* parent;
        }tree;
        bool inserted;
        void free(struct node* leaf){
            if(!leaf) return;
            struct node* lt = leaf->lt, *rt = leaf->rt;
            delete leaf;
            free(lt);
            free(rt);
        }
        void print(tree *t){
            if (!t) return;
	        print(t->lt);
	        cout << t->data << endl;
	        print(t->rt);
        }
        void push(tree* p, T a){
            if(!p->lt || !is_num(p->lt->data)){
                if(!p->lt){
                    p->lt = new tree;
                    p->lt->data = a;
                    p->lt->lt = NULL;
                    p->lt->rt = NULL;
                    p->lt->parent = p;
                    inserted = true;
                }
                else{
                    push(p->lt, a);
                }
            }
            if(!inserted && (!p->rt || !is_num(p->rt->data))){
                if(!p->rt){
                    p->rt = new tree;
                    p->rt->data = a;
                    p->rt->lt = NULL;
                    p->rt->rt = NULL;
                    p->rt->parent = p;
                    inserted = true;
                }
                else{
                    push(p->rt, a);
                }
            }
        }

        void prefix(tree* p){
            if (!p) return;
            cout << p->data << " ";
	        prefix(p->lt);
	        prefix(p->rt);
        }
        void postfix(tree* p){
            if (!p) return;
	        postfix(p->lt);
	        postfix(p->rt);
            cout << p->data << " ";
        }
        void infix(tree* p){
            if (!p) return;
	        infix(p->lt);
            cout << p->data << " ";
	        infix(p->rt);
        }
        string div(int a, int b){
            if(!b){
                return "No";
            }
            return to_string(a / b);
        }
        string comp(tree* p){
            if(!p)
                return "No";
            if(is_num(p->data))
                return string(1, p->data);
            string a = comp(p->lt), b = comp(p->rt);
            if(a == "No" || b == "No")
                return "No";
            int x = stoi(a), y = stoi(b);
            switch(p->data){
                case '*':
                    return to_string(x * y);
                    break;
                case '+':
                    return to_string(x + y);
                    break;
                case '-':
                    return to_string(x - y);
                    break;
                case '/':
                    return div(x, y);
                    break;
                default:
                    return string(1, p->data);
                    break;
            }
        }
        tree* Tr;

    public:
        BinTree(){
            Tr = NULL;
        }
        ~BinTree(){
            free(Tr);
        }
        void print_tree(){
            print(Tr->lt);
            cout << Tr->data << endl;
            print(Tr->rt);
        }
        void add(T a){
            inserted = false;
            if(!Tr){
                Tr = new tree;
                Tr->data = a;
                Tr->lt = NULL;
                Tr->rt = NULL;
                Tr->parent = NULL;
                inserted = true;
            }
            else if(!Tr->lt || !is_num(Tr->lt->data)){
                if(!Tr->lt){
                    Tr->lt = new tree;
                    Tr->lt->data = a;
                    Tr->lt->lt = NULL;
                    Tr->lt->rt = NULL;
                    Tr->lt->parent = Tr;
                    inserted = true;
                }
                else{
                    push(Tr->lt, a);
                }
            }
            if(!inserted && (!Tr->rt || !is_num(Tr->rt->data))){
                if(!Tr->rt){
                    Tr->rt = new tree;
                    Tr->rt->data = a;
                    Tr->rt->lt = NULL;
                    Tr->rt->rt = NULL;
                    Tr->rt->parent = Tr;
                    inserted = true;
                }
                else{
                    push(Tr->rt, a);
                }
            }
        }
        void print_prefix(){
            cout << Tr->data << " ";
            prefix(Tr->lt);
            prefix(Tr->rt);
            cout << endl;
        }

        void print_postfix(){
            postfix(Tr->lt);
            postfix(Tr->rt);
            cout << Tr->data << endl;
        }
        string compute(){
            if(!Tr)
                return "No";
            if(is_num(Tr->data))
                return string(1, Tr->data);
            string a = comp(Tr->lt), b = comp(Tr->rt);
            if(a == "No" || b == "No")
                return "No";
            int x = stoi(a), y = stoi(b);
            switch(Tr->data){
                case '*':
                    return to_string(x * y);
                    break;
                case '+':
                    return to_string(x + y);
                    break;
                case '-':
                    return to_string(x - y);
                    break;
                case '/':
                    return div(x, y);
                    break;
                default:
                    return string(1, Tr->data);
                    break;
            }
        }
};

int main(){
    BinTree<char> tree;
    char c;
    while(cin >> c){
        tree.add(c);
    }
    // tree.print_tree();
    cout << tree.compute();
}