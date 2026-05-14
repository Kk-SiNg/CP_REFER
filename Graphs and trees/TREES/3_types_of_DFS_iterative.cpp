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

// we will use stack as:- print the current top and rmeove it then insert it's *right child* first then left child cuz we need left child
// to be processed earlier hence on top of stack.
void preorder_iterative(struct node* root){
    stack <struct node*> stc; 
    stc.push(root);

    while(!stc.empty()){
        struct node *current_node = stc.top();
        stc.pop();
        cout << current_node->data << " ";
        if(current_node->right!= NULL) stc.push(current_node->right);
        if(current_node->left != NULL) stc.push(current_node->left);
    }
}

//logic:- went left until the left of current_node == NULL(pushing the current_node on top of stack in the meantime) => their is no left
//child so, now change the current_node to right child while printing and then popping the top;
//if right child != NULL then continue inserting the left's. As soon as we gat current_child as NULL we print the parent_node move to it's
//right and pop the stack, if right is also NULL then parent gets printed. 
//Suppose we are at a leaf node then we will have current leaf node on top of stack, it will be printed and then stack is popped,
//current_node will be the right of this leaf node, now since the very current_node == NULL and we have the parent of leaf_node on top of
//stack hence, parent will be printed, then we check the right of parent and so on...
//IN SIMPLE WORDS algo is that push into the stack until cirrent_node is null, if is null then pop and print the top.
//Note---> this is exactly how the recursion stack is working.
void inorder_iterative(struct node* root){
    stack <struct node*> stc; 
    stc.push(root);
    struct node *current_node = stc.top();
    while(!stc.empty() || current_node != NULL){
        if(current_node != NULL){
            stc.push(current_node);
            current_node = current_node->left;
        }
        else{
            current_node = stc.top();    //restore to previous node which was not null
            cout << current_node->data << " ";
            stc.pop();
            current_node = current_node->right;
        }
    }
}

//logic:- pop the current_top of stc1 to stc2 and push the left and <then> right of current node. Feel that this will ensure that parent
//is pushed into stc2 at earliest and then right and then left, hence while we extract from stc2 we will have the answer in reversed order.
void postorder_iterative(struct node* root){
    stack <struct node*> stc1;
    stack <int> stc2;
    stc1.push(root);
    
    while(!stc1.empty()){
        struct node *current_node = stc1.top();
        stc1.pop();
        stc2.push(current_node->data);

        if(current_node->left != NULL) stc1.push(current_node->left);
        if(current_node->right != NULL) stc1.push(current_node->right);
    }
    while(!stc2.empty()){
        cout << stc2.top() << " ";
        stc2.pop();
    }
    cout << "\n";
}


int main(){

}