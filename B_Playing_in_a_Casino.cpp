#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n, m, a;
    cin >> n >> m;
    vector<ll>temp(m,0);
    vector <vector<ll>> vect(n,temp);

    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            cin >> a;
            vect[i][j] = a;
        }
    }
    if(n == 1){
        cout << 0 << "\n";
        return;
    }
    ll ans = 0;
    for(ll i = 0; i < m; i++){
        vector <ll> t;
        for(ll j = 0; j < n; j++){
            t.push_back(vect[j][i]);
        }
        sort(t.begin(), t.end());
        vector <ll> pf;
        ll sm = 0;
        for(ll it:t){
            sm += it;
            pf.push_back(sm);
        }
        for(ll i = 1; i < n; i++){
            ans += (i+1)*(t[i]) - pf[i];
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