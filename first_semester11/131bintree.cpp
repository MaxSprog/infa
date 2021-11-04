#include <string>
#include <iostream>

using namespace std;

class BinTree{
    private:
        typedef struct node {
            string data;
            struct node* rt;
            struct node* lt;
        }tree;
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
        void push(tree* p, string a){
            if(p->data > a){
                if(!p->lt){
                    p->lt = new tree;
                    p->lt->data = a;
                    p->lt->lt = NULL;
                    p->lt->rt = NULL;
                    return;
                }
                push(p->lt, a);
            }
            else if(p->data < a){
                if(!p->rt){
                    p->rt = new tree;
                    p->rt->data = a;
                    p->rt->lt = NULL;
                    p->rt->rt = NULL;
                    return;
                }
                push(p->rt, a);
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
        tree* Tr;

    public:
        BinTree(){
            Tr = new tree;
            Tr->data = "";
            Tr->rt = NULL;
            Tr->lt = NULL;
        }
        ~BinTree(){
            free(Tr);
        }
        void print_tree(){
            print(Tr->lt);
            cout << Tr->data << endl;
            print(Tr->rt);
        }
        void add(string a){
            if(Tr->data == ""){
                Tr->data = a;
            }
            else if(Tr->data > a){
                if(!Tr->lt){
                    Tr->lt = new tree;
                    Tr->lt->data = a;
                    Tr->lt->lt = NULL;
                    Tr->lt->rt = NULL;
                }
                else{
                    push(Tr->lt, a);
                }
            }
            else if(Tr->data < a){
                if(!Tr->rt){
                    Tr->rt = new tree;
                    Tr->rt->data = a;
                    Tr->rt->lt = NULL;
                    Tr->rt->rt = NULL;
                }
                else{
                    push(Tr->rt, a);
                }
            }
        }
};

int main(){
    BinTree tree;
    string s;
    while(cin >> s){
        tree.add(s);
    }
    tree.print_tree();
}