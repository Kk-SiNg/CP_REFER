#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    string s, str;
    cin >> s;
    ll ctr = 0;
    for(char ch:s){
        if(ch == '4') ctr++;
        else str += ch;
    }
    ll n = str.length();
    ll odds = 0, evens = 0;
    bool flg = 0;
    for(char ch:str){
        if(ch == '2'){
            if(odds > 0){
                ctr++;
                odds--;
            }
        }
        else odds++;
    }
    cout << ctr << "\n";
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