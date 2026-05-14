#include <bits/stdc++.h>
using namespace std;

const int N = 10e5+5;
int INF = 10e9 + 10;

array <vector<pair<int,int>>, N> graph;
//TC:- O(n*ln(n))
//note:- djkestras will find the shortest path from source node to all the other nodes.
void djkestras(int source){
    vector<int> vis(N, 0);
    vector<int> dist(N, INF);   //take all the distances to other vertices from source node = infinity at begining
    set <pair<int, int>> st;    //set will also work fine in place of priority queue, it stores <distance, node> and top ele = min_dist

    st.insert({0, source});
    dist[source] = 0;

    while(st.size() > 0){       //process--->we will go to min dist node traverse through it's childs if we find shorter dist to any of
                                //child then new optimised path found => add it in set

        auto node = *st.begin();     //we begin from source node
        int vertex = node.second;   
        if(vis[vertex]) continue;    //FEEL!! that in each iteration if a vertex is unvisited then we are visiting it, but now we will
//never be able to visit this node. That means the current path for this node should be the min dist path, cuz this node is visited now.
//And the above claim is completely true cuz--->think like we are processing the node on top of priority_queue i.e. the current min dist
//node present in queue and when we insert the children of this top node and any other node dist will always be >= dist of top_node. Hence
//the current path to the element being currently processed is actually min.

        vis[vertex] = 1;             //we will mark a node as visited once all of it's child are covered

        st.erase(st.begin());

        for(auto child: graph[vertex]){
            int child_v = child.first;
            int wt = child.second;
            if (dist[vertex] + wt < dist[child_v]){
                dist[child_v] = dist[vertex] + wt;
                st.insert({dist[child_v], child_v});    // updating set as soon as shorter or more optimised path to that node is found
            }
        }
    }
} 
//note:- Djkestras will fail if we have negative weights, cuz it's a greedy algo i.e. while processing a node it is marked as visited and
//assuming that the current dist to this node is min, but it can be minimised furteher since we have negative weights. note that current
//code is TLE free cuz we maintained a visited array, but ans is still Wrong.

int main(){
    int n, m;
    cin >> n >> m;
    int x, y , wt;          // for storing directed graph from node x to y with weight wt

    for(int i = 0; i < m; i++){
        cin >> x >> y >> wt;
        graph[x].push_back({y, wt});
    }
    djkestras(1);
}