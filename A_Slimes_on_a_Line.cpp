#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n, a;
    vector <ll> vect;  
    cin >> n;
    ll maxi = 0;
    ll mini = 1000+1;
    for(ll i = 0; i < n; i++){
        cin >> a;
        mini = min(mini, a);
        maxi = max(maxi, a);
    }
    ll avg = (mini+maxi)/2;
    cout  << max(avg-mini, maxi-avg) << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}