#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n, a;
    vector <ll> vect;  
    cin >> n;
    for(ll i = 0; i < n; i++){
        cin >> a;
        vect.push_back(a);
    }
    ll mx = 0;
    for(ll i = 0; i < n-1; i++){
        if(vect[i] > vect[i+1]) mx = max(mx, vect[i]-vect[i+1]);
    }
    for(ll i = 0; i < n-1; i++){
        if(vect[i] > vect[i+1]) vect[i+1]+=mx;
    }
    for(ll i = 0; i < n-1; i++){
        if(vect[i] > vect[i+1]) {cout << "NO\n"; return;}
    }
    cout << "YES\n";
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