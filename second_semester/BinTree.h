#pragma once
#include <cstddef>
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
            else{
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

    public:
        tree* Tr;
        BinTree();
        ~BinTree();
        void print_tree();
        void add(string a);
        void print_prefix();
        void print_postfix();
        void print_infix();
};