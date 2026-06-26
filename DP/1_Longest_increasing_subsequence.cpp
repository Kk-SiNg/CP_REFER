#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N = 1e5+1;
vector <int> dp(N, 0);

int recur(int idx, int n, vector <int> &vect){
    
    if(dp[idx] > 0) return dp[idx];
    int ans = 1;
    for(int i = 0; i < idx; i++){
        if(vect[i] <= vect[idx]) ans = max(ans, recur(i, n, vect) +1);
    }
    return dp[idx] = ans;
}


void solve(){
    int n, a;
    vector <int> vect;  
    vector <int> ans, ds;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        vect.push_back(a);
    }
    int final_ans = 1;
    for(int i = 0; i < n; i++){
        final_ans = max(final_ans, recur(i, n, vect));
    }
    cout << final_ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while(t--){
        solve();
    }
}