//simply use a flag which tells us whether current level is to be traversed l->r or r->l.

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

void zig_zag_traversal(struct node *root){
    queue <struct node*> q;
    vector <vector<int>> traversal_result_level_wise;
    q.push(root);
    bool flg = 0;       //0 means left->right traversal
    while(!q.empty()){
        int n = q.size();
        vector <int> temp_level(n);
        for(int i = 0; i < n; i++){
            struct node *current_node = q.front();
            q.pop();
            int idx = i;
            if(flg) idx = n-i-1;
            temp_level[idx] = current_node->data;

            if(current_node->left != NULL) q.push(current_node->left);
            if(current_node->right!= NULL) q.push(current_node->right);
        }
        traversal_result_level_wise.push_back(temp_level);
    }
}



int main(){

}