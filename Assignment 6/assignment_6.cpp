#include <iostream>
#include "assignment_6.h"
using namespace std;



binaryTree::binaryTree(){
    root = NULL;
}
//function to call main add function
void binaryTree::insert(int new_value){
    root = add(new_value, root);
}
//add a new node to the tree
Node* binaryTree::add(int new_value, Node *leaf){
    if(leaf == NULL){       //empty tree
        leaf = new Node;
        leaf->value = new_value;
        leaf->left = leaf->right = leaf->parent = NULL;
    }
    else if(new_value < leaf->value){       //go left
        leaf->left = add(new_value, leaf->left);
        leaf->left->parent = leaf;
    }
    else if(new_value > leaf->value){       //go right
        leaf->right = add(new_value, leaf->right);
        leaf->right->parent = leaf;
    }
    return leaf;
}
//utility function for remove; gets the minimum node from a given subtree
Node* binaryTree::get_min(Node *leaf){
    while(leaf->left != NULL){
        leaf = leaf->left;
    }
    return leaf;
}
//function to call the main remove function
void binaryTree::remove(int old_value){
    root = Remove(old_value, root);
}

//remove a node a choose a successor if needed
Node* binaryTree::Remove(int old_value, Node *leaf){
    if(leaf == NULL){
        return NULL;
    }
    else if(old_value < leaf->value){       //go left
        leaf->left = Remove(old_value, leaf->left);
    }
    else if(old_value > leaf->value){       //go right
        leaf->right = Remove(old_value, leaf->right);
    }
    else{       //at this point, recursion has found the node to be deleted
        //if the node has no children
        if(leaf->left == NULL && leaf->right == NULL){
            delete leaf;
            leaf = NULL;
        }
        //if the node has 1 child
        else if(leaf->left == NULL){
            Node *temp = leaf;
            leaf->right->parent = leaf->parent;
            leaf = leaf->right;
            delete temp;
        }
        else if(leaf->right == NULL){
            Node *temp = leaf;
            leaf->left->parent = leaf->parent;
            leaf = leaf->left;
            delete temp;
        }
        //if the node has 2 children, we find the min in right subtree,
        //replace root's value with that min value, then delete the node
        //that originally held that min value
        else{
            Node *temp = get_min(leaf->right);
            leaf->value = temp->value;
            leaf->right = Remove(temp->value, leaf->right);
        }
    }
    return leaf;
}

//inorder traversal
void binaryTree::inorder(Node *leaf){
    if(leaf == NULL){
        return;
    }
    inorder(leaf->left);
    cout << leaf->value << ", ";
    inorder(leaf->right);  
}
//preorder traversal
void binaryTree::preorder(Node *leaf){
    if(leaf == NULL){
        return;
    }
    cout << leaf->value << ", ";
    preorder(leaf->left);
    preorder(leaf->right);
}  
//postorder
void binaryTree::postorder(Node *leaf){
    if(leaf == NULL){
        return;
    }
    postorder(leaf->left);
    postorder(leaf->right);
    cout << leaf->value << ", ";
} 
//display the tree inorder
void binaryTree::print_inorder(){
    inorder(root);
}       
//display it preorder
void binaryTree::print_preorder(){
    preorder(root);
}
//display it postorder
void binaryTree::print_postorder(){
    postorder(root);
}
