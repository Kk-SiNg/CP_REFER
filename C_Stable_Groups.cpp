#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n, k, x, a;
    vector <ll> vect;  
    cin >> n >> k >> x;
    for(ll i = 0; i < n; i++){
        cin >> a;
        vect.push_back(a);
    }
    
    sort(vect.begin(), vect.end());
    vector <ll> gp;
    for(ll i = 0; i < n-1; i++){
        if(vect[i+1]-vect[i] == 0) continue;
        gp.push_back((vect[i+1]-vect[i]-1)/x);
    }
    ll ans = gp.size();
    sort(gp.begin(), gp.end());
    // for(auto it: gp) cout << it << " ";
    // cout << "\n";
    for(ll i = 0; i < gp.size(); i++){
        k -= gp[i];
        if(k < 0) break;
        ans --;
    }
    cout << ans+1 << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    while(t--){
        solve();
    }
}