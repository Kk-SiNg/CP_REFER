#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n, q, a;
    cin >> n >> q;
    ll sum = 0;
    unordered_map <ll,ll> mp1;
    for(ll i = 0; i < n; i++){
        cin >> a;
        sum += a;
        mp1[i] = a;
    }

    ll t, idx, ele;
    ll tr = 0;
    while(q--){
        cin >> t;
        if(t == 2) {
            cin >> ele;
            sum = n*ele;
            tr = ele;
            cout << sum << "\n";
            break;
        }
        cin >> idx >> ele;
        sum -= mp1[idx-1];
        sum += ele;
        mp1[idx-1] = ele;
        cout << sum << "\n";
    }


    unordered_map <ll,ll> mp;
    while(q--){
        cin >> t;
        if(t == 1){
            cin >> idx >> ele;
            if(mp.find(idx-1) != mp.end()) sum -= mp[idx-1];
            else sum -= tr;
            mp[idx-1] = ele;
            sum+=ele;
            cout << sum << "\n";
        }
        else{
            cin >> ele;
            sum = n*ele;
            tr = ele;
            mp.clear();
            cout << sum << "\n";
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    solve();
}