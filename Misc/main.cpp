#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int a = 2;
    cout << a++ << a++ << "\n";
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