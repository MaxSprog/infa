#include "BinTree.cpp"

int main(){
    BinTree tree;
    tree.add("a");
    tree.add("t");
    tree.add("b");
    tree.add("g");
    tree.add("c");
    tree.add("z");
    tree.print_tree();
    cout << "----------" << endl;
    tree.print_prefix();
    cout << "----------" << endl;
    tree.print_postfix();
    cout << "----------" << endl;
    tree.print_infix();
}