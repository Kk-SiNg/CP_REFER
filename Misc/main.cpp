#include <bits/stdc++.h>
using namespace std;


int dp[200][200];
int recur(int i, int j, vector<vector<int>>& grid){
    if(i-1 < 0 && j-1 < 0) return 0;
    else if(i-1 < 0 || j-1 < 0) return 200;
    if(dp[i][j] != INT_MAX) return dp[i][j];
    return dp[i][j] = min(recur(i-1, j, grid), recur(i, j-1, grid)) + grid[i][j];
}
int minPathSum(vector<vector<int>>& grid) {
    for(int i = 0; i < 200; i++){
        for(int j = 0; j < 200; j++){
            dp[i][j] = 200;
        }
    }
    dp[0][0] = grid[0][0];
    int n = grid.size();
    int m = grid[1].size();
    recur(n-1,m-1, grid);

    return(dp[n-1][m-1]);
}

int main() {
    int n, m;
    cin >> n >> m;
}
