#include <bits/stdc++.h>
using namespace std;
#define ll long long

void recur(ll n){
    if(n == 0) return;
    recur(n/10);
    cout << n%10 << " ";
}

void solve(){
    ll n, a;
    cin >> n;
    recur(n);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--){
        solve();
        cout << "\n";
    }
}