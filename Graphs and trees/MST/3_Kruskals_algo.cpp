#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
array <int, N> parent;
array <int, N> Size;

//DSU
void make(int n){
    parent[n] = n;
}
int find(int n){
    if(parent[n] == n) return n;
    return parent[n] = find(parent[n]);
}
void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        if(Size[b] > Size[a]) swap(a,b);
        parent[b] = a;
        Size[a] += Size[b];
    }
}


//logic:- sort in increasing order of weights then pick up edges starting from min_wt to max_wt and if a cycle is not formed due to
//        insertion then all good.
int main(){
    vector <pair<int, pair<int,int>>> edges;    //stores (wt,(x,y))
    int n, m;
    cin >> n >> m;  
    int x, y, wt;
    for(int i = 0; i < m; i++){
        cin >> x >> y >> wt;
        edges.push_back({wt, {x,y}});
    }
    sort(edges.begin(), edges.end());

    for(int i = 1; i <= n; i++) make(i);    //create n independent nodes in DSU

    int MST_wt = 0;
    for(auto it:edges){
        int weight = it.first;
        int a = it.second.first;
        int b = it.second.second;

        if(find(a) != find(b)){     //if a and b are in same connected component then surely cycle will form while inserting new edge
            MST_wt += weight;
            Union(a,b);
        }
    }
}