#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
array <vector<int>, N> g;
array <int, N> sum;

//Q. you are allowed to delete any 1 edge, find the max value of (product of sum of two formed subtrees) possibe.
//logic:- Precompute what is asked, like here max value of product of sum of two formed trees is asked, so we will precompute sums of 
//        every subtree while saving it to corresponding vertex(root of subtree), now simply travel through all edges looking for max
//TC:-O(N)
void dfs(int vertex, int parent){
    sum[vertex] += vertex;
    for(int child:g[vertex]){
        if(parent == child) continue;

        dfs(child, vertex);
        sum[vertex] += sum[child];
    }
}

int main(){
    int n;
    cin >> n;
    int x, y;

    for(int i = 0; i < n-1; i++){
        cin >> x >> y;
        g[x].push_back(x);
        g[y].push_back(y);
    }
    dfs(1,0);
    int ans = 0;
    for(int i = 2; i <= n; i++){
        int part_one_sum = sum[i];
        int part_two_sum = sum[1] - sum[i];
        ans = max(part_one_sum*part_two_sum, ans);
    }
    cout << ans << "\n";
}