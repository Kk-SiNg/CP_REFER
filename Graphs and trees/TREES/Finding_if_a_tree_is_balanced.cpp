//a balanced tree have abs(left_height - r_height) <= 1, so we will use same dfs approach as used in finding the height of tree with extra
//constrains added

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

int find_height_dfs(struct node *root){
    if(root == NULL) return 0;

    int l_height = find_height_dfs(root->left);
    if(l_height == -1) return -1;                   //this is the follow up of the third commented line, As soon as it is executed then
                                                    //we'll keep returning -1 until recursion stack is exhausted
    int r_height = find_height_dfs(root->right);
    if(r_height == -1) return -1;

    if(abs(r_height - l_height) > 1) return -1;     //orignal condition of balanced tree.
    return 1 + max(l_height, r_height);
}

int main(){

}