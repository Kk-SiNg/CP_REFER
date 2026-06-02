#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n, a;
    cin >> n;
    vector <bool> hash(n+1, 0);
    string s;
    cin >> s;

    ll ans = 0;
    for(int i = 1; i <= n; i++){
        for(int idx = i; idx <= n; idx+=i){
            if(s[idx-1] == '1') break;
            if(!hash[idx]) ans += i;
            hash[idx] = 1;
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