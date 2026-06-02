#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n, s, a;
    vector <ll> vect;  
    cin >> n >> s;
    ll ext = 0;
    for(ll i = 0; i < n; i++){
        cin >> a;
        ext += a;
        vect.push_back(a);
    }
    if(ext < s) {cout << "-1\n"; return;}
    else if(ext == s){cout << 0 << "\n"; return;}
    
    ll r = 0;
    while(ext > s){
        if(vect[r] == 1) ext--;
        r++;
    }
    r--;

    ll rr = n-1;
    ll sum = s;
    ll ans = r+1;
    while(rr >= 0 && r >= 0){
        if(vect[rr] == 1) sum++;
        while(r >= 0 && sum >= s){
            if(vect[r] == 1 && sum == s) {break;}
            if(vect[r] == 1) sum--;
            r--;
        }
        if(sum == s) ans = min(ans, (r+1 + n-rr));
        rr--;
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