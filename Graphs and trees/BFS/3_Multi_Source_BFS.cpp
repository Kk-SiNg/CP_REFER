#include <bits/stdc++.h>
using namespace std;

//Q_variations:-
//1. Suppose we are given a graph with k initial source node then they may ask the min time required to reach some node.
//2. We migth be asked to cover a GRID starting with multiple sources in some chain reaction type of thing(given some constraints).

//FEEL!--->since we are using level array hence if from any other source the level of target node is lesser than only new path will be
//         considered, forgetting old one. i.e. when we inserted multiple sources simultaniously then their children and then more child...
//         then what we are doing is essentially calculating the min distance to the node being processed from all other nodes and since
//         we are maintaining a level array hence their is always a scope that later we may find some other path that will get smaller path
//         but this later will always come quite soon in 0-1 BFS, cuz as soon as we insert an ele with 0 wt then it will be inserted in
//         front(essentially behaving like at the same level as parent).

//Q.you are given a n*m grid, in one operation every element in grid = max(neighbours), where neighbour = any ele sharing a corner or side.
//  find the min operations required so that after that their is no more variation in grid.
//ans:- feel that if we had only 1 source then the answer would have been the max level found in grid starting BFS from the idx of this max
//      ele(Source). But since multiple sources are possible hence use multi-source BFS.
//Note:- the above logic is correct but for this question we can simply use a visited array cuz weights are 1, and once a node is visited
//       it is surely guranteed that we visited it via shortest path.

const int N = 1e3+5;
int INF = 1e9;
int grid[N][N];
int visited[N][N];
int level[N][N];
int n, m;

void reset(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            level[i][j] = 0;
            visited[i][j] = 0;
        }
    }
}

vector <pair<int,int>> directions = {
    {0,1}, {0,-1}, {1,0}, {-1,0},
    {1,1}, {-1,1}, {-1,-1}, {1,-1} 
};

bool is_valid(int x, int y){
    if(x < 0 || x >= n) return 0;
    if(y < 0 || y >= n) return 0;
    return 1;
}

void solve(){
    cin >> n >> m;
    int a;
    int mx = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a;
            grid[i][j] = a;
            mx = max(mx, a);
        }
    }
    reset();

    queue <pair<int, int>> q;
    for(int i = 0; i < n; i++){         //initialise queue with all sources.
        for(int j = 0; j < m; j++){
            if(grid[i][j] == mx){
                q.push({i,j});
                visited[i][j] = 1;
            }
        }
    }

    int max_dist = 0;
    while(!q.empty()){
        int current_y = q.front().first, current_x = q.front().second;
        q.pop();

        for(int i = 0; i < 8; i++){
            int child_x = current_x + directions[i].first;
            int child_y = current_y + directions[i].second;
            
            if(!(is_valid(child_x, child_y))) continue;
            if(visited[child_x][child_y]) continue;
            q.push({child_x,child_y});
            visited[child_x][child_y] = 1;
            level[child_x][child_y] = level[current_x][current_y] +1;
            max_dist = max(max_dist, level[child_x][child_y]);
        }
    }
    cout << max_dist << "\n";
}


int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}