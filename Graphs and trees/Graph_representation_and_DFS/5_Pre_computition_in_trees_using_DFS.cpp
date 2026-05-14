#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
array <vector<int>, N> g;
array <int, N> sum;
array <int, N> evens;

//Q1. precompute the sum of every subtree of given adjacency_list
//Q2. precompute the number of even ele present in every subtree.
//logic:- we have to calculate sum/evens_count while backtracking from below, so when all childs are processed we start backracking.
//        And do care that we have to add current vertex's val to the sum of subtree of that vertex.

void dfs(int vertex, int parent){
    // for every vertex personally
    sum[vertex] += vertex;
    if(vertex%2 == 0) evens[vertex]++;

    for(int child:g[vertex]){
        if(child == parent) continue;

        dfs(child, vertex);
        // for considering data gathered by every child of current vertex which will serve further it's parent until finally root node.
        sum[vertex] += sum[child];
        evens[vertex] += evens[child];
    }
}



int main(){
    int n;  //number of nodes
    cin >> n;
    
    int x, y;
    for(int i = 0; i < n-1; i++){
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1, 0);
}