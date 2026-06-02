#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll ans = 1e9+1;

void recur(ll idx, ll sum, vector <ll> &vect, ll n, ll ts){
    if(idx >= n){
        ans = min(ans, abs(2*sum - ts));
        return;
    }
    sum += vect[idx];
    recur(idx+1, sum, vect, n, ts);
    sum -= vect[idx];
    recur(idx+1, sum, vect, n, ts);
}

void solve(){
    ll n, a;
    vector <ll> vect;  
    cin >> n;
    ll ts = 0;
    for(ll i = 0; i < n; i++){
        cin >> a;
        vect.push_back(a);
        ts += a;
    }
    recur(0,0,vect,n,ts);
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    t = 1;
    while(t--){
        solve();
    }
}