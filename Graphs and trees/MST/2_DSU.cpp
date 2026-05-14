#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+2;
array <int, N> parent;
array <int, N> Size;

//add an independent node in DSU-datastructure
void make(int n){               
    parent[n] = n;
    Size[n] = 1;
}
//return the root(highest parent) of tree containing "n"
int find(int n){               
    if(parent[n] == n) return n;
    //path compression:- think like since parent array is used only to find the root of all the nodes connected to current root in a
    //connected component, hence once root is found then while backtracking we can change the parents of all the nodes encountered in path
    //to root node directly.
    return parent[n] = find(parent[n]);
}
//joins two unconnected components(essentially make a link b/w the roots of tree containng a and b)
void Union_unoptimised(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b) parent[b] = a;   //both are unconnected
}
//note:- it would be benificial if we make the bigger tree as parent of smaller, if we do opposite than size/depth will increse.
//solution:- Union by <Size>/rank(depth):-
void Union_optimised(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        if(Size[a] < Size[b]) swap(a,b);        //simply make "a" of bigger size and then make "a", which is bigger as parent of "b".
        parent[b] = a;
        Size[a] += Size[b];
    }
}

int main(){
    int n, e;
    cin >> n >> e;
    int a, b;

    for(int i=1; i <= n; i++){
        make(i);
    }
    while(e--){
        cin >> a >> b;
        Union_optimised(a,b);
    }

    //finding connected components:-
    //logic:- only those conponents whose parent==ele_itself represent the root_nodes and number of root nodes is answer
    int ctr = 0;
    for(int i = 1; i <= n; i++){
        if(parent[i] == i) ctr++;
    }
    cout << "connected comp:- " << ctr << "\n";
}