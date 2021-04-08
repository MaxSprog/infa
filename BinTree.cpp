#include "BinTree.h"

BinTree::BinTree(){
    Tr = new tree;
    Tr->data = "";
    Tr->rt = NULL;
    Tr->lt = NULL;
}

BinTree::~BinTree(){
    freehalfjoint(Tr);
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
