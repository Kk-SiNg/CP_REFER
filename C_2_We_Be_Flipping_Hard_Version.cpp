#include <bits/stdc++.h>
using namespace std;
#define ll long long

void minimise(vector<ll> &vect, ll n, ll r, vector <ll> &ans){
    bool flg = 0;
    ll sm = 0;
    for(ll i = r-1; i >= 0; i--){
        if(vect[i] < 0 && !flg) {
            continue;
        }
        else if(vect[i] > 0 && flg) {
            continue;
        }
        ans.push_back(i+1);
        flg ^= 1;
    }
}


void solve(){
    ll n, a;
    cin >> n;
    vector <ll> vect;  
    vector <ll> sf(n, 0);
    vector <ll> pf(n,0);
    ll sm = 0;
    for(ll i = 0; i < n; i++){
        cin >> a;
        sm += a;
        vect.push_back(a);
    }
    for(ll i = n-2; i >= 0; i--){
        sf[i] = sf[i+1]+vect[i+1];
    }
    for(ll i = 1; i < n; i++){
        pf[i] = pf[i-1] + abs(vect[i-1]);
    }

    vector <ll> ans;
    int pivot = -1;
    for(ll i = 0; i < n; i++){
        if(vect[i] > 0){
            // cout << pf[i] + sf[i] - vect[i] << " " << sm << "\n";
            if((pf[i] + sf[i] - vect[i]) > sm){
                sm = (pf[i] + sf[i] - vect[i]);
                pivot = i;
            }
        }
    }

    if(pivot == -1) {cout << "0\n";return;}
    minimise(vect, n, pivot, ans);
    ans.push_back(pivot+1);

    cout << ans.size();
    cout << "\n";
    for(ll it:ans) cout << it << " ";
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