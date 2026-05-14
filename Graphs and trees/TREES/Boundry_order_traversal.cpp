//so the logic to cover the full boundry is to cover the left/right boundries saparately and leaf nodes separately
//left boundry ---> go to left of current_node and iff left is unavailable then go to right and as-soon-as left and right both == NULL
//then stop cuz we don't want to include a leaf node twice.
//leaf nodes ---> do a inorder traversal or any other, and when leaf node is found(both left and right == NULL) then add it to the array.
//right boundry--->start from root->right and store nodes in a stack with priority to right(opposite of left boundry)

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

void boundry_order_traversal(struct node *root){
    
}



int main(){

}