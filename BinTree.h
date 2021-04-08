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
        void freejoint(struct node* right, struct node* left){
            struct node* rr = right->rt, *rl = right->lt, *lr = left->rt, *ll = left->lt;
            delete right;
            delete left;
            if(rr == NULL){
                if(rl != NULL){
                    freehalfjoint(rl);
                }
                else{
                    return;
                }
            }
            else{
                freejoint(rr, rl);
            }
            if(lr == NULL){
                if(ll != NULL){
                    freehalfjoint(ll);
                }
                else{
                    return;
                }
            }
            else{
                freejoint(lr, ll);
            }
        }
        void freehalfjoint(struct node* stick){
            struct node* r = stick->rt, *l = stick->lt;
            delete stick;
            if(r == NULL){
                if(l != NULL){
                    freehalfjoint(l);
                }
                else{
                    return;
                }
            }
            else if(l == NULL){
                freehalfjoint(r);
            }
            else{
                freejoint(r, l);
            }
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

    public:
        tree* Tr;
        BinTree();
        ~BinTree();
        void print_tree();
        void add(string a);
};