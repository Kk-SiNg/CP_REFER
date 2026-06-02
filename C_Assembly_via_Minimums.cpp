#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n, a;
    cin >> n;
    map <ll,ll> hash;
    for(ll i = 0; i < n*(n-1)/2; i++){
        cin >> a;
        hash[a]++;
    }
    
    ll cur = 0;

    for(auto it = hash.rbegin(); it != hash.rend(); it++){
        ll req = it->second;
        ll r = 1;
        while(cur*r + (r*r-1)/2 < req) r++;
        cur += r;
        while(r > 0){
            cout << it->first << " ";
            r--;
        }
    }
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