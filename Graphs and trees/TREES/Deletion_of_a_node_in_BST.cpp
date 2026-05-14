// The deletion process in BST depends on the number of children of the node:-
// a. No children means simply remove the node.
// b. One child means remove the node and connect its parent to the node’s only child.
// c. Two children means replace the node with its inorder successor/predecessor and delete that node.

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

//first we need to find if the target exist
struct node* find_ele(struct node *root ,int target){
    while(root != NULL){
        if(root->data == target) return root;
        else if(root->data < target) root = root->right;
        else root = root->left;
    }
    return root;
}

//find the just greater ele than target node, i.e. the inorder successor
struct node *find_inorder_successor(struct node *root){
    while(root->left != NULL) root = root->left;
    return root;
}
struct node *find_parent(struct node *root, struct node *target_child){
    while(root->left != target_child || root->right != target_child){
        if(root->data < target_child->data) root = root->right;
        else root = root->left;
    }
    return root;
}
void del(struct node *root, int target){
    struct node *target_node = find_ele(root, target);
    if(target_node == NULL) return;             //no such target val exist
    if(target_node->right == NULL && target_node->left == NULL) delete target_node;     //leaf node to be deleted
    else if(target_node->left == NULL){         //2 cases where only one child is present.
        struct node *parent = find_parent(root, target_node);
        if(parent->right == target_node) parent->right = target_node->right;
        else parent->left = target_node->right;
    }
    else if(target_node->right == NULL){
        struct node *parent = find_parent(root, target_node);
        if(parent->right == target_node) parent->right = target_node->left;
        else parent->left = target_node->left;
    }
    else{       //case when both left and right child are present.
        struct node *successor = find_inorder_successor(target_node);
        target_node->data = successor->data;

        if(successor->right != NULL){
            struct node *parent = find_parent(root, successor);
            parent->left = successor->right;
        }
    }
}

int main(){

}