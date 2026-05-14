#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
array <vector<int>, N> g;
array <int, N> par;

//Q. find the lowest common ancestor of given two nodes.
//logic:- calculate the path from root->1st node and root->2nd node than everything in the starting till the last common node will
//        be common in both path arrays, so loop for 1st diff/last_common while comparing both the path arrays.

//Finding path--->first we store parents of each vertex using dfs, then in path() function, to find the path from root to vertex(v), save
//v and then change it to parent of v(saved in par-array), and as we root the parent of root which is -1 here then exit the loop.
void dfs(int vertex, int parent = -1){
    par[vertex] = parent;

    for(int child:g[vertex]){
        if(child == parent) continue;
        dfs(child, vertex);
    }
}

vector <int> path(int v){
    vector <int> ans;
    while(v != -1){
        ans.push_back(v);
        v = par[v];
    }
    reverse(ans.begin(), ans.end());    //since ans will be in reversed order w.r.t node so reverse it to get it in order of
                                        //commons(starting from root)
    return ans;
}

int main(){
    int n; 
    cin >> n;
    int x, y;

    for(int i = 0; i < n-1; i++){
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cin >> x >> y;
    dfs(1);
    vector <int> path_x = path(x);
    vector <int> path_y = path(y);

    int t = min(path_x.size(), path_y.size());
    for(int i = 0; i < t; i++){
        if(path_x[i] != path_y[i]){cout << path_x[i-1] << "\n"; break;}
    }
    cout << path_x[t-1] << "\n";
}