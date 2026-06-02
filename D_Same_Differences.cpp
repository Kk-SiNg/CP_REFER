#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n, a;
    vector <ll> vect;  
    cin >> n;
    for(ll i = 0; i < n; i++){
        cin >> a;
        vect.push_back(a-(i+1));
    }
    sort(vect.begin(), vect.end());
    ll ans = 0;
    ll len = 1;
    for(ll i = 0; i < n-1; i++){
        if(vect[i] == vect[i+1]) {len++; continue;}
        ans += len*(len-1)/2;
        len = 1;
    }
    ans += len*(len-1)/2;
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