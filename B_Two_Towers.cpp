#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a > b){
        a = b;
        c = d;
    }
    int ans = 0;
    ans += abs(a - min(b,c));

    if(b<c){
        ans += min(c,d) - b;
        ans += abs(c-d);
        // cout << "a ";
    }
    else{
        ans += d-b;
        // cout << "b ";
    }
    cout << ans << "\n";
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