#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
array <vector<int>, N> g;
array <int, N> height;
array <int, N> depth;

//logic:- 1. for depth---> register the depth of the child *before entering* it (or) the depth of a node after entering it
//        2. for height--> when we start backtracking from a child, i.e. initially from one of leaf's, then we register the current node as
//           the max of it's current val(cuz multiple child may lead their way to same vertex) and child's_val+1 
void dfs(int vertex, int parent){
    for(int child:g[vertex]){
        if(child == parent) continue;   //note that for a tree no need of visited array as no cycles, just pay care not to revisit parent
        
        depth[child] = depth[vertex]+1;
        dfs(child, vertex);
        height[vertex] = max(height[vertex], height[child]+1);
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
    for(int i = 1; i <= n; i++) cout << height[i];
    cout << "\n";
    for(int i = 1; i <= n; i++) cout << depth[i];
    cout << "\n";
}