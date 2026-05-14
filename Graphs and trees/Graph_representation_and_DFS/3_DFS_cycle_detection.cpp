#include <iostream>
#include <vector>
#include <array>

using namespace std;


const int N = 10e3;
array <vector<int>, N> graph;
bool visited_lst[N];

//logic:- 
// 1. if we encounter an already visited node while traversal and it is not the node that we came from then cycle exist.
// 2. so maintain a var "parent" node of current vertex, so that we can ignore checking it for condition of cycle
bool dfs(int vertex, int parent){  
    visited_lst[vertex] = 1;
    bool isCycleExist = false;          //feel that for every vertex we are checking if a cycle exist with current vertex as starting
                                        //point(i.e. we have visited rest of part of cycle and now if a child of current vertex is visited
                                        //then start returning true while backtracking to start), hence initialising it with false
                                        //initially.
    for(int child : graph[vertex]){         
        if(child == parent) continue;
        if(visited_lst[child]) return true; //note that as soon as a visited_non_current_parent node is found then cycle detected in the
                                            //current vertex.
        isCycleExist |= dfs(child, vertex);
    }
    return isCycleExist;                    //as traversal for all the childs finishes return if cycle exist for current vertex(taken-or
                                            //with all vertices traversed yet).
}

int main(){
    int n, m;
    cin >> n >> m;
    int x, y;

    for(int i = 0; i < m; i++){
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for(int i = 1; i <= n; i++){
        if(visited_lst[i] == 1) continue;
        if(dfs(i,1)) {cout << "cycle exist\n"; return 0;}
    }
    cout << "no cycle\n";
}