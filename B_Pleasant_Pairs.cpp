#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n, a;
    vector <ll> vect;  
    cin >> n;
    unordered_map <ll, ll> mp;
    for(ll i = 0; i < n; i++){
        cin >> a;
        mp[a] = i+1;
        vect.push_back(a);
    }
    ll ans = 0;
    sort(vect.begin(), vect.end());
    for(ll i = 0; i < n; i++){
        for(ll j = i+1; j < n; j++){
            if(vect[i]*vect[j] > (2*n-1)) break;
            if(mp[vect[i]] + mp[vect[j]] == vect[i]*vect[j]) ans++;
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