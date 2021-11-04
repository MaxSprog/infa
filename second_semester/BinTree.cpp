#include "BinTree.h"

template<class T>
BinTree::BinTree(){
    Tr = NULL;
}

template<class T>
BinTree::~BinTree(){
    free(Tr);
}

template<class T>
void BinTree::print_tree(){
	print(Tr->lt);
	cout << Tr->data << endl;
	print(Tr->rt);
}

template<class T>
void BinTree::add(T a){
	if(!Tr){
        Tr = new tree;
        Tr->data = a;
        Tr->lt = NULL;
        Tr->rt = NULL;
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
    else{
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

template<class T>
void BinTree::print_prefix(){
	cout << Tr->data << " ";
	prefix(Tr->lt);
	prefix(Tr->rt);
    cout << endl;
}

template<class T>
void BinTree::print_postfix(){
	postfix(Tr->lt);
	postfix(Tr->rt);
	cout << Tr->data << endl;
}

template<class T>
void BinTree::print_infix(){
	infix(Tr->lt);
	cout << Tr->data << " ";
	infix(Tr->rt);
    cout << endl;
}