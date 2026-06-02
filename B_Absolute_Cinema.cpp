#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n, x;
    vector <ll> a, b;  
    cin >> n;
    ll maxi = 0;
    ll idx;
    for(ll i = 0; i < n; i++){
        cin >> x;
        a.push_back(x);
        if(x > maxi){
            maxi = x;
            idx = i;
        }
    }
    for(ll i = 0; i < n; i++){
        cin >> x;
        b.push_back(x);
        if(x > maxi){
            maxi = x;
            idx = i;
        }
    }

    ll ans = 0;
    for(ll i = 0; i < n; i++){
        ans += max(a[i], b[i]);
    }
    ll fact = 0;
    for(ll i = 0; i < n; i++){
        ll mn = min(a[i], b[i]);
        fact = max(fact, mn);
    }
    cout << ans + fact << "\n";
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