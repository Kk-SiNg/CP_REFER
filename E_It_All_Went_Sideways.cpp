#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll invert(vector <ll> &vect, ll n, ll ans, ll idx){
    ll mini = 2*1e5 + 5;
    vect[idx]--;
    for(ll i = n-1; i >= 0; i--){
        if(vect[i] <= mini) ans -= vect[i];
        else ans-=mini;
        mini = min(mini, vect[i]);
    }
    vect[idx]++;
    return ans;
}


void solve(){
    ll n, a;
    vector <ll> vect;
    ll ans = 0;
    cin >> n;
    ll min_idx = 0;
    for(ll i = 0; i < n; i++){
        cin >> a;
        ans += a;
        vect.push_back(a);
        if(a <= vect[min_idx]) min_idx = i;
    }
    
    ans--;
    ll final_ans = -2e18;
    for(ll i = 0; i < n; i++){
        final_ans = max(final_ans, invert(vect, n, ans, i));
    }
    cout << final_ans << "\n";
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