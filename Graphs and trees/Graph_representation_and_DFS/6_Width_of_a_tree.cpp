#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
array <vector<int>, N> g;
array <int, N> depth;

//logic:- we will first calculate one of the ends of max width by finding max_depths, note that if i run DFS from any node than the end
//        points of depth, taking that node as root will shurely have one of end point as that of the orignal tree with orignal root node
//        so simply find one of end_point's and then run another dfs from this point and we'll have 2nd end point too.
void dfs(int vertex, int parent){

    for(int child:g[vertex]){
        if(child == parent) continue;

        depth[child] = depth[vertex]+1;
        dfs(child, vertex);
    }
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

    dfs(1, 0);
    int max_depth = -1, max_depth_node;
    for(int i = 1; i <= n; i++){
        if(depth[i] > max_depth){
            max_depth = depth[i];
            max_depth_node = i;
        }
        depth[i] = 0;   //empty depths to be reused below.
    }

    dfs(max_depth_node, 0);
    max_depth = -1;
    for(int i = 1; i <= n; i++){
        if(depth[i] > max_depth){
            max_depth = depth[i];
            max_depth_node = i;
        }
        depth[i] = 0;
    }
    cout << max_depth << "\n";
}