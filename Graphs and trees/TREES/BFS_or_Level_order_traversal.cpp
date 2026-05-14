//We will use FIFO property of queue---> insert all the childs of current node then pop it from queue, repeat this process for number of 
//ele in current_level times so as to remove all the ele of current level and include all the ele of next level, then again take the size
//of queue and repeat this process for size number of times to get next level and so on...

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

void BFS(struct node *root){
    queue <struct node*> q;
    q.push(root);
    vector <vector<int>> tree;

    while(!q.empty()){
        int sz = q.size();       //we need to empty these older level elements while pushing new elements from current level
        vector <int> level;
        for(int i = 0; i < sz; i++){
            struct node *current_node = q.front();
            if(current_node->left != NULL) q.push(current_node->left);
            if(current_node->right != NULL) q.push(current_node->right);
            level.push_back(q.front()->data);
            q.pop();
        }
        tree.push_back(level);
    }
}


int main(){

}