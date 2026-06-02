#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n, a;
    vector <ll> vect;  
    cin >> n;
    for(ll i = 0; i < n; i++){
        cin >> a;
        vect.push_back(a);
    }
    if(n == 1) cout << 1 << "\n";
    else{
        ll ans = 2;
        bool flg = 0, f = 0;

        for(int i = 0; i < n-1; i++){
            if(vect[i+1] > vect[i]){ flg = 1, f = 1; break;}
            else if(vect[i+1] < vect[i]){ flg = 0, f = 1; break;}
        }
        if(!f) {cout << "1\n";return;}

        for(ll i= 0; i < n-1; i++){
            if(flg){
                if(vect[i+1] < vect[i]){
                    ans++;
                    flg = 0;
                }
            }
            else{
                if(vect[i+1] > vect[i]){
                    ans++;
                    flg = 1;
                }
            }
        }
        cout << ans << "\n";
    }
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