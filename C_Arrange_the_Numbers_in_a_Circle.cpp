#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n, a;
    vector <ll> vect;
    cin >> n;
    ll tot = 0;
    ll g_s = 0;
    for(ll i = 0; i < n; i++){
        cin >> a;
        tot += a;
        if(a >= 2) g_s++;
        vect.push_back(a);
    }

    if(tot < 3){
        cout << 0 << "\n";
        return;
    }
    
    ll extras = 0;
    ll vacancy = 0;
    ll ans = 0;
    for(auto it:vect){
        if(it == 1){
            extras++;
            continue;
        }
        ans += it;
        vacancy += ((it/2)-1);
    }
    ans += min(vacancy, extras);
    extras -= min(vacancy, extras);
    if(extras >= 1 && g_s == 1) ans++;
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