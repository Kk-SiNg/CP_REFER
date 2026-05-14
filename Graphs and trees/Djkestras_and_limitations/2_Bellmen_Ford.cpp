#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int INF = 1e8+10;
array <vector<pair<int,int>>, N> g;
vector <int> dist(N, INF);
int n, m;

//TC:- O(nodes*edges)
//logic:-1.we will execute the same update condition as that of djkestra's i.e. if:dist[current_x] + wt < dist[current_y] then we update
//        dist[current_x] to new one. We will perform these (m-1) times covering all the nodes(n) in each iteration. Now feel that we need 
//        min of 1 iteration and max of [edges-1] iterations.
//       2.note both edge_list and adjacency_list will work here.
void Bellmen_ford(){
    dist[1] = 0;
    for(int i = 0; i < m-1; i++){       //loop m-1_times
        for(int j = 1; j <= n; j++){
            if(dist[j] >= INF) continue;//node is not visited yet, so we can't update it's childrens

            for(auto k:g[j]){           //go through all childs of vertex.
                int curr_x = j, curr_y = k.first, wt = k.second;
                if(dist[curr_x] + wt < dist[curr_y]) dist[curr_y] = dist[curr_x] + wt;      //relax the edge
            }
        }
    }
    //now after m-1 iterations of bulk relaxations, we will get the dist array static, i.e. it should not change by performing any further
    //iteration, but iff negative cycles are present then the above statement is false. Hence now we will perform one more iteration to
    //detect negative-cycle.
    bool flg = 0;
    for(int j = 1; j <= n; j++){
        if(dist[j] == INF) continue;

        for(auto k:g[j]){
            int curr_x = j, curr_y = k.first, wt = k.second;
            if(dist[curr_x] + wt < dist[curr_y]) dist[curr_y] = dist[curr_x] + wt, flg = 1;      //relax the edge
        }
    }
    if(flg) cout << "negative cycle present\n";
    else cout << "no negative cycle\n"; 
}



int main(){
    cin >> n >> m;
    int x, y, wt;
    for(int i = 0; i < m; i++){
        cin >> x >> y >> wt;
        g[x].push_back({y,wt});
    }
    Bellmen_ford();
    for(int i = 1; i <= n; i++) cout << i << ' ' << dist[i] << "\n";
    cout << "\n";
}