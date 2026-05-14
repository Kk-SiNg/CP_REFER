#include <bits/stdc++.h>
using namespace std;


//Q. given a directed graph find the min number of edges that needs to be reversed so that their exists atleast one path from node 1->N
//logics:- 1. first think that while making adjacency list we'll put the given edge with weigth 0 and an edge reverse to it with penalty
//            weight 1.
//         2. now feel that this is a question of 0-1 BFS where we put the child with weight 0 in front of queue(treating as it is in same
//            level as that of parent) and child with weight 1 at the back like normal BFS. And hence the shortest 0-1 BFS path(level)
//            will be the min reversals required.
//         3. Also feel that at a time their can be at max of 2 levels in queue, that's why we can put node with 0wt on upper level as
//            (parent level) compared to a node attached to parent with 1 wt(to be put on next level)

const int N = 1e5 +5;
const long int INF = 1e9;

array<vector<pair<int, int>>, N> g;
array <int, N> level = {INF};

int BFS(int n){
    deque<int> q;           //to push elements on front and back
    q.push_back(1);         //source = 1, goal = n
    level[1] = 0;

    while(!q.empty()){
        int current_node = q.front();
        q.pop_front();

        for(auto child:g[current_node]){
            int current_child = child.first;
            int current_wt = child.second;

            if((level[current_node] + current_wt) < (level[current_child])){     //this is ensuring that if we already have current node
//regestered with a level say 2 with parent p, but while processing rest of childs of p it may happen that we get even shorter path(say
//the direct wt between p and node is 1 but their exist 2 nodes st one is connected to p with 0 wt and then this to another node with 0 wt
//and then this 2nd node finally to our required node with another 0 wt, hence total 0 path cost), that's why we can't use a visited array.
//also observe that this "if" can be executed at max of 2*edges times cuz first we might get a 1 cost route and <then> a 0 cost route
                level[current_child] = level[current_node] + current_wt;
                if(current_wt == 1){
                    q.push_back(current_child);
                }
                else if(current_wt == 0){
                    q.push_front(current_child);
                }
            }
        }
    }
    return level[n];
}

int main(){

    int n , e;
    cin >> n >> e;
    int x, y;

    for(int i = 0; i < e; i++){
        cin >> x >> y;           //this indicates that there is a unidirectional edge from x to y(always given in Q.)
        g[x].push_back({y, 0});  //we assign 0 wt to given edge
        g[y].push_back({x, 1});  //and insert a reverse edge which will cost 1 wt
    }
}