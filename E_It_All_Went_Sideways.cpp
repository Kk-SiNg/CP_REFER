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
    map <int, int> mp;
    int mini = 1e9+1;
    for(int i = n-1; i >= 0; i--){
        if(vect[i] < mini) mp[vect[i]] = i, mini = vect[i];
    }
    vector <int> temp;
    for(auto it:mp){
        temp.push_back(it.first);
    }
    int m_len = mp[temp[0]];
    int idx = mp[temp[0]];
    for(int i = 0; i < temp.size()-1; i++){
        if(mp[temp[i+1]] - mp[temp[i]]-1 >= m_len){
            idx = mp[temp[i+1]];
            m_len = mp[temp[i+1]] - mp[temp[i]]-1;
        }
    }
    // cout << idx << " ";
    cout << invert(vect, n, ans, idx) << "\n";
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