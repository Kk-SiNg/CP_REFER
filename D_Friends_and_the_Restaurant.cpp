#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n, a;
    vector <ll> x, y;  
    vector <ll> am, gm;
    cin >> n;
    for(ll i = 0; i < n; i++){
        cin >> a;
        x.push_back(a);
    }
    for(ll i = 0; i < n; i++){
        cin >> a;
        y.push_back(a);
    }
    
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        if(x[i] > y[i]) gm.push_back(x[i]-y[i]);
        else if(x[i] == y[i]) {ans++;continue;}
        else am.push_back(y[i]-x[i]), ans++;
    }
    sort(am.begin(), am.end());
    sort(gm.begin(), gm.end());

    a = am.size();
    ll g = gm.size();
    ll i = 0, j = 0;
    while(i < a && j < g){
        while(am[i] < gm[j])i++;
        if(i >= a) break;
        ans++;
        j++;
        i++;
    }
    cout << ans/2 << "\n";
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