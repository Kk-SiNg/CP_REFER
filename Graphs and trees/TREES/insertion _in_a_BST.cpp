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

//Logic:- find the leaf position where the target should have been in O(height) and again for this we will explicitly search for target 
//and since target in not on BST hence we will finally reach a parent who should be holding the target node, the while loop ends when we
//get current node as null.
void insert(struct node *root, int target){
    if(root == NULL) {root->data = target; return;}
    struct node *current_node = root;

    while(true){
        if(current_node->data < target){
            if(current_node->right != NULL) current_node = current_node->right;
            else{
                current_node->right = new node(target);
                break;
            }
        }
        else if(current_node->data > target){
            if(current_node->left != NULL) current_node = current_node->left;
            else{
                current_node->left = new node(target);
                break;
            }
        }
    }
}



int main(){

}