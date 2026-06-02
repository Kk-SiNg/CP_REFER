#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n, a;
    vector <ll> vect;
    map <ll,ll> mp;
    cin >> n;
    for(ll i = 0; i < n; i++){
        cin >> a;
        mp[a]++;
    }
    ll ans = 0;
    for(auto it:mp){
        if(it.second > 0){
            ans += it.second;
            ll cur = it.first;
            ll tr = it.second;
            while(true){
                cur++;
                if(mp.find(cur) != mp.end()){
                    if(tr > mp[cur]) tr = mp[cur], mp[cur] = 0;
                    else mp[cur] -= tr;
                }
                else break;
            }
        }
    }
    cout << ans << "\n";
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