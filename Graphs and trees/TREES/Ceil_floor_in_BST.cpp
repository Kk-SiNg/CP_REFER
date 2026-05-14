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

//TC: O(height)
//simply maintain a variable that stores the closest greatest element encountered yet
int ceil(struct node *root, int target){
    int ceil = -1;
    while(root != NULL){
        if(root->data == target){
            ceil = root->data;
            break;
        }
        if(root->data < target) root = root->right;
            
        else{
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
}

//maintain a variable that stores the closest smaller than ele to target.
int floor(struct node *root, int target){
    int floor = -1;
    while(root != NULL){
        if(root->data == target){
            floor = root->data;
            break;
        }
        if(root->data > target) root = root->left;

        else{
            floor = root->data;
            root = root->right;     //so as to get max ele <= target.
        }
    }
    return floor;
}

int main(){

}