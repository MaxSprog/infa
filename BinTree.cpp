#include "BinTree.h"

BinTree::BinTree(){
    Tr = new tree;
    Tr->data = "";
    Tr->rt = NULL;
    Tr->lt = NULL;
}

BinTree::~BinTree(){
    free(Tr);
}

void BinTree::print_tree(){
	print(Tr->lt);
	cout << Tr->data << endl;
	print(Tr->rt);
}


void BinTree::add(string a){
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

void BinTree::print_prefix(){
	cout << Tr->data << " ";
	prefix(Tr->lt);
	prefix(Tr->rt);
    cout << endl;
}

void BinTree::print_postfix(){
	postfix(Tr->lt);
	postfix(Tr->rt);
	cout << Tr->data << endl;
}

void BinTree::print_infix(){
	infix(Tr->lt);
	cout << Tr->data << " ";
	infix(Tr->rt);
    cout << endl;
}