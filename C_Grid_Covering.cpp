#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    if(__gcd(m,b) > 1 || __gcd(n,a) > 1 || (__gcd(m,n) > 1 && m!=n)) cout << "NO\n";
    else cout << "YES\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}