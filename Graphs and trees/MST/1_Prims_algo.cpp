#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
array <vector<pair<int,int>>, N> g;

int n, m;

//Feel!! of algo:-think as suppose we inserted 0th node at begining in Priority_queue(pq) then their has to be some connection b/w 0th node
//                and any other node. so we pick up the node with least wt and mark the 0th as visited so that their is no chance st: we
//                arrive at this node back. this taking min wt and visiting the processed node is driving the algo to take only smaller wt
//                available. also feel that we are doing the visiting process in reverse manner i.e. if i am standing at some node(curr_n)
//                then we are trying to establish exactly one link that lead to curr_n to get MST(and since we are using priority_queue it
//                is guranteed that whenever we are establishing a link that leads to curr_n then it carries min possible wt of edges
//                checked till now, but it can be true that their might be a link with curr_n to other node with lesser wt, but it will 
//                automatically be covered in next step when we insert all the unvisted childs of curr_n, i.e. it will be used to go to
//                some other node from curr_n, contributing to overall MST; finally their might be question that what if that child with
//                lesser wt is marked visited--->so think that it is not possible until that child has some better wt to use).
int prims_algo(){
    set <vector<int>> pq;              //will work as priority queue
    vector <int> visited(N,0);
    vector <pair<int, int>> mst_edges; //to store final MST edges.
    int mst_wt = 0;                    //min possible sum of all the n-1 edges in MST.

    pq.insert({0,0,-1});               // wt, child(curr_n), parent. Note:-we don't need to carry parent iff "only wt of MST" is asked.
//note the role of each of the {wt, x, parnet}--->wt is first parameter so least wt node to be processed will always be at top, parent is
//used to generate a spanning tree.
    while(!pq.empty()){
        auto it = *pq.begin();
        pq.erase(pq.begin());

        int wt = it[0];
        int curr_n = it[1];
        int parent = it[2];

        if(visited[curr_n]) continue;

        visited[curr_n] = 1;
        mst_wt += wt;
        if(parent != -1) mst_edges.push_back({parent, curr_n});
        for(auto neighbor : g[curr_n]){
            int adj_node = neighbor.first;
            int edge_wt = neighbor.second;
            if(!visited[adj_node]){
                pq.insert({edge_wt, adj_node, curr_n});
            }
        }
    }

    for(auto edge : mst_edges){
        cout << edge.first << "  " << edge.second << "\n";
    }

    return mst_wt;
}

int main(){
    cin >> n >> m;
    int x, y, wt;
    for(int i = 0; i < m; i++){
        cin >> x >> y >> wt;
        g[x].push_back({y,wt});     //prism's algo need undirected graph.
        g[y].push_back({x,wt});
    }

    int mst_wt = prims_algo();
    cout << "wt of mst formed" << mst_wt << "\n";

    return 0;
}