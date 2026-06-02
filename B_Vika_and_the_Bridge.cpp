#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n, k, a;
    cin >> n >> k;
    vector <ll> vect(n+1,0);  
    unordered_map <ll,ll> hash;
    unordered_map <ll,pair<ll,ll>> maxi;

    for(ll i = 1; i <= n; i++){
        cin >> a;
        vect[i] = a;
        hash[a] = 0;
        maxi[a] = {0,0};
    }
    for(ll i = 1; i <= n; i++){
        ll diff = i - hash[vect[i]];
        if(diff > maxi[vect[i]].second){
            maxi[vect[i]].first = maxi[vect[i]].second;
            maxi[vect[i]].second = diff;
        }
        else if(diff >= maxi[vect[i]].first){
            maxi[vect[i]].first = diff;
        }
        hash[vect[i]] = i;
    }
    for(ll i = 1; i <= k; i++){
        ll diff = n+1 - hash[i];
        if(diff > maxi[i].second){
            maxi[i].first = maxi[i].second;
            maxi[i].second = diff;
        }
        else if(diff > maxi[i].first){
            maxi[i].first = diff;
        }
    }
    ll min_jumps = 2e5 + 5;
    for(auto it:maxi){
        ll gp = it.second.second;
        if(gp%2 == 0){
            gp = gp/2 - 1;
        }
        else gp = gp/2;

        min_jumps = min(min_jumps, max(gp, it.second.first -1));
    }
    cout << min_jumps << "\n";
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