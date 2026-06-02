#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n, x, a;
    vector <ll> vect;  
    cin >> n >> x;
    for(ll i = 0; i < n; i++){
        cin >> a;
        vect.push_back(a);
    }
    sort(vect.begin(), vect.end());

    ll sum = 0;
    ll ans = 0;
    ll len = 0;
    for(ll i = 0; i < n; i++){
        if(sum+vect[i] > x) break;
        sum += vect[i];
        len++;
    }

    ll days = 0;
    while(len >= 1){
        ll ad = 1 + (x-sum)/len;
        ans += len*ad;
        days+=ad;
        sum+=(len)*ad;
        while(len >= 1 && sum > x){
            sum -= days;
            sum -= vect[len-1];
            len--;
        }
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