#include<iostream>
#include<cassert>
#include "assignment_6.h"
using namespace std;

//test that nodes are added appropriately, tests preorder traversal aswell for the display
void test_add(){
    binaryTree tree;
    tree.insert(40);
    tree.insert(25);
    tree.insert(10);
    tree.insert(32);
    tree.insert(55);
    tree.insert(78);
    tree.print_preorder();
}

//test that a node can be removed properly and an appropriate successor can be chosen. tests funcionality of find_min and inorder traversal
void test_remove(){
    binaryTree tree;
    tree.insert(40);
    tree.insert(25);
    tree.insert(10);
    tree.insert(32);
    tree.insert(55);
    tree.insert(78);
    tree.remove(25);
    tree.print_inorder();
}

//final test for the postorder traversal
void test_postorder(){
    binaryTree tree;
    tree.insert(40);
    tree.insert(25);
    tree.insert(10);
    tree.insert(32);
    tree.insert(55);
    tree.insert(78);
    tree.remove(25);
    tree.print_postorder();
}

int main(){
    cout <<"Sample Tree:\n";
    cout <<"            "<<40<<"\n";
    cout <<"        "<<25<<"      "<<55<<"\n";
    cout <<"      "<<10<<"  "<<32<<"      "<<78<<"\n";
    cout <<"Preorder Traversal:\n";
    test_add();
    cout <<"\nInorder traversal after removal of node with value 25:\n";
    test_remove();
    cout<<"\nPostorder traversal: (25 still removed)\n";
    test_postorder();
    return 0;
}