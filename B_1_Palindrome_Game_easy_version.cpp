#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n, a;
    string s;
    cin >> n >> s;

    if(n==1 && s[0] == '0') {cout << "BOB\n"; return;}
    int ct = 0;
    for(char ch:s) if(ch == '0') ct++;
    if(n%2 == 1 && s[n/2] == '0' && ct > 1) {cout << "ALICE\n"; return;}
    else if(ct >= 1) {cout << "BOB\n"; return;}
    cout << "DRAW\n";
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