//logic:- while standing at a node we'll take the height of a node as the 1+ max(left_subtree_height, right...), do this recursively.
//TC:- O(n), we will have to go through all the nodes

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

int find_height(struct node* root){
    if(root == NULL) return 0;

    int l_height = find_height(root->left);
    int r_height = find_height(root->right);

    return 1 + max(l_height, r_height);
}


int main(){

}