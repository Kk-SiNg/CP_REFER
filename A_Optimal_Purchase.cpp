#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n, a, b;
    cin >> n >> a >> b;

    ll cost = 0;
    if(b >= 3*a) cost = n*a;
    else if(b >= 2*a) cost = (n/3)*b + (n%3)*a;
    else if(b >= a){
        cost = (n/3)*b;
        if(n%3 == 2) cost += b;
        else if(n%3 == 1) cost += a;
    }
    else{
        cost = (n/3)*b;
        if(n % 3 != 0) cost += b;
    }
    cout << cost << "\n";
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