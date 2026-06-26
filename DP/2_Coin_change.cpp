#include <bits/stdc++.h>
using namespace std;
#define ll long long

//Find the nuber of combinations of given coins possible to achieve the given amount.
vector <int> temp(310, -1);
vector <vector<int>> dp(5010, temp);

int recur(int idx, int target, int n, vector <int> &coins){
    if(target == 0) return 1;
    if(idx == n) return 0;
    if(dp[idx][target] != -1) return(dp[idx][target]);
    
    int ans = 0;
    int d_target = target;
    while(d_target >= 0){
        ans += recur(idx+1, d_target, n, coins);
        d_target -= coins[idx];
    }
    return dp[idx][target] = ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;

    int amount, a;
    int n;
    cin >> amount;
    cin >> n; 
    vector <int> coins;

    for(int i = 0; i < n; i++){
        cin >> a;
        coins.push_back(a);
    }

    while(t--){
        cout << (recur(0, amount, coins.size(), coins));
    }
}