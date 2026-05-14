//the three tyrpes of DFS are:-
//1. preorder ---> parent, left, right
//2. inorder ----> left, parent, right
//3. postorder --> left, right, parent
// note:- they simply mean which one to prefer while performing a given operation, like suppose we are given task to print all nodes in
// preorder than while stnding at a parent we will print it and then process the left and then right child and so on for others...

#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node*left;
    node*right;
    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preorder(struct node *root){
    if(root == NULL) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node *root){
    if(root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(struct node *root){
    if(root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main(){

}