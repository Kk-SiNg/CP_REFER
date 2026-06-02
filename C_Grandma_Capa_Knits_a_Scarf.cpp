#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll optimise(string str, ll n, char ch){
    ll l = 0, r = n-1;
    ll cost = 0;
    while(l < r){
        if(str[l] == str[r]);
        else if(str[l] == ch) {l++; cost++; continue;}
        else if(str[r] == ch) {r--; cost++; continue;}
        else return -1;
        l++, r--;
    }
    return cost;
}


void solve(){
    ll n, a;
    cin >> n;
    string str;
    cin >> str;

    ll l = 0, r = n-1;
    char ch_1 = ' ', ch_2 = ' ';
    while(l <= r){
        if(str[l] != str[r]) {ch_1 = str[l], ch_2 = str[r]; break;}
        l++, r--;
    }
    if(ch_1 == ' ') {cout << 0 << "\n"; return;}

    ll op_1 = optimise(str, n, ch_1), op_2 = optimise(str, n, ch_2);
    if(op_1 == -1 && op_2 == -1) cout << -1;
    else if(op_1 == -1) cout << op_2;
    else if(op_2 == -1) cout << op_1;
    else cout << min(op_1, op_2);
    cout << "\n";
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