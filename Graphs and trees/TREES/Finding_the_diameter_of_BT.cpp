//diameter of a BT is the max path length between any two nodes and this path need not pass via root

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


//M1. traverse through each node find l_height + r_height compare it with max_height found yet and move on to next node
//TC:- O(n^2)
int max_len = 0;
int find_height(struct node *root){
    if(root == NULL) return 0;

    int left_height =find_height(root->left);
    int right_height =find_height(root->right);

    return 1+max(left_height, right_height);
}

void find_max_dia_brute(struct node *root){
    if(root == NULL) return;

    int left_height = find_height(root->left);
    int right_height = find_height(root->right);

    max_len = max(left_height+right_height, max_len);
    find_max_dia_brute(root->left);
    find_max_dia_brute(root->right);
}

//M2. while finding the height of a tree we have left_height and right_height as the two variables collecting the max height of left and
//right subtrees saparately. So since we have these max l/r heights for every node simply check for their sum for max at this intant

int maxi = 0;
int find_maxi_during_height_calc(struct node *root){
    if(root == NULL) return 0;
    
    int lh = find_maxi_during_height_calc(root->left);
    int rh = find_maxi_during_height_calc(root->right);

    maxi = max(maxi, lh+rh);
    return 1 + max(lh, rh);
}

int main(){

}