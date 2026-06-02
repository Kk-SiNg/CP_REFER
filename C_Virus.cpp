#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n, m, a;
    vector <ll> vect;  
    vector <ll> stretch;
    cin >> n >> m;
    for(ll i = 0; i < m; i++){
        cin >> a;
        vect.push_back(a);
    }
    sort(vect.begin(), vect.end());
    for(ll i = 0; i < m-1; i++){
        if(vect[i+1] - vect[i]-1 > 0) stretch.push_back(vect[i+1] - vect[i]-1);
    }
    if(vect[0]-1 + n-vect[m-1] > 0) stretch.push_back(vect[0]-1 + n-vect[m-1]);

    sort(stretch.begin(), stretch.end());
    ll moves = 0;
    ll saved = 0;
    m = stretch.size();
    for(ll i = m-1; i >= 0; i--){
        if((stretch[i]- moves*2 - 1) < 0) break;
        if((stretch[i]- moves*2 - 1) == 0) saved++;
        else saved += stretch[i]- moves*2 - 1;
        moves+=2;
    }
    cout << n-saved << "\n";
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