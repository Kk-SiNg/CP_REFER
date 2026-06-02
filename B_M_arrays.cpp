#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n, m, a;
    vector <ll> vect;
    map <ll,ll> mp;
    cin >> n >> m;
    bool flg = 0;
    for(ll i = 0; i < n; i++){
        cin >> a;
        if(a%m == 0) {flg = 1;continue;}
        mp[a%m]++;
    }
    int ans = 0;
    if(flg) ans++;
    for(auto it:mp){
        ll num = it.first;
        if(num > (m)/2) {ans += mp[num]; continue;}
        if(mp.find(m-num) == mp.end()) {ans += it.second; continue;}
        ans += max(0ll,abs(mp[num]-mp[m-num])-1)+1;
        mp[m-num] = 0;
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