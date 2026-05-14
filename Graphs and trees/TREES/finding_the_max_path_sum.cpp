//we will use the same logic as that of finding the diameter, except that we will return values of node rather than 1.

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

int maxi = 0;
int find_max_path_sum(struct node *root){
    if(root == NULL) return 0;

    int l_sum = find_max_path_sum(root->left);
    int r_sum = find_max_path_sum(root->right);

    maxi = max(maxi, l_sum+r_sum+root->data);
    return root->data + max(l_sum, r_sum);
}

int main(){

}
