#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n, q, a;
    map <ll,ll> mp;
    cin >> n >> q;
    ll sum = 0;
    ll maxi = 0;
    for(ll i = 0; i < n; i++){
        cin >> a;
        maxi = max(maxi, a);
        sum += a;
        mp[maxi] = sum;
    }
    ll h = mp.size();
    while(q--){
        cin >> a;
        auto it = mp.lower_bound(a);
        if(it != mp.end() && it->first == a);
        else if(it == mp.begin()){
            cout << 0 << " ";
            continue;
        }
        else it--;

        cout << it->second << " ";
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