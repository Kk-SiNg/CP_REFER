#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll find_msb(ll num){
    for(ll i = 31; i >= 0; i--){
        if((num>>i)&1) return i;
    }
    return 0;
}
void solve(){
    ll n, a;
    vector <ll> vect;  
    cin >> n;
    map <ll, ll> mp;
    for(ll i = 0; i < n; i++){
        cin >> a;
        mp[find_msb(a)]++;
    }
    ll ans = 0;
    for(auto it:mp){
        ll x = it.second;
        ans += x*(x-1)/2;
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