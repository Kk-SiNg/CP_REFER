#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n, k, a;
    map <ll,ll> mp;  
    cin >> n >> k;
    for(ll i = 0; i < n; i++){
        cin >> a;
        mp[a] = 0;
    }
    
    vector <ll> ans;
    bool flg = 0;
    for(auto it:mp){
        if(it.second == 1) continue;
        ll cp = it.first;
        ans.push_back(cp);
        while(cp <= k){
            if(mp.find(cp) != mp.end()) mp[cp] = 1;
            else {flg = 1; break;}
            cp += it.first;
        }
        if(flg) break;
    }
    if(flg){
        cout << "-1\n";
        return;
    }
    cout << ans.size() << "\n";
    for(ll it:ans) cout << it << ' ';
    cout << "\n"; 
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