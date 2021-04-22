#include "BinTree.cpp"

int main(){
    BinTree tree;
    tree.add("4");
    tree.add("*");
    tree.add("5");
    tree.add("/");
    tree.add("10");
    tree.print_tree();
    cout << "----------" << endl;
    tree.print_prefix();
    cout << "----------" << endl;
    tree.print_postfix();
    cout << "----------" << endl;
    tree.print_infix();
}