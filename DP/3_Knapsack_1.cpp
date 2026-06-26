#include <bits/stdc++.h>
using namespace std;

long long dp[105][100005];

long long recur(long long target, long long idx, long long n, vector <long long> &a, vector <long long> &b){
    if(target == 0) return 0;
    if(idx < 0) return INT_MAX;
    if(dp[idx][target] != -1) return(dp[idx][target]);

    long long mn = 1e15;
    if(target - b[idx] >= 0) mn = min(mn, recur(target-b[idx], idx-1, n, a, b)+a[idx]);
    mn = min(mn, recur(target, idx-1, n, a, b));

    return dp[idx][target] = mn;
}

int main(){
    long long n, k;
    cin >> n >> k;
    long long x, y;
    vector <long long> a, b;
    for(int i = 0; i < 105; i++){
        for(int j = 0; j < 100005; j++){
            dp[i][j] = -1;
        }
    }
    for(long long i = 0; i < n; i++){
        cin >> x >> y;
        a.push_back(x);
        b.push_back(y);
    }

    int N = 1e5;
    for(int i = N; i > 1; i--){
        if(recur(i, n-1, n, a, b) <= k){
            cout << i << "\n";
            return 0;
        }
    }
    cout << "-1\n";
}