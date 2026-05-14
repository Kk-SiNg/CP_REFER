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

//if current node's data < target then move to right subtree, else move to right subtree
struct node* search(int target, struct node *root){
    while(root != NULL || root->data != target){
        if(root->data < target) root = root->right;
        else root = root->left;
    }
    return root;
}

int main(){

}