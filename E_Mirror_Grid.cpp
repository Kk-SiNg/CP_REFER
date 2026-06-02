#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll check2(vector<vector<ll>> &vect, ll n, ll i, ll j){
    ll ones = 0, zeroes = 0;
    if(vect[i][j] == 1) ones++;
    else zeroes++;
    if(vect[j][n-i-1] == 1) ones++;
    else zeroes++;
    if(vect[n-i-1][n-j-1] == 1) ones++;
    else zeroes++;
    if(vect[n-j-1][i] == 1) ones++;
    else zeroes++;
    return(min(ones, zeroes));
}

void solve(){
    ll n, a;
    cin >> n;
    string str;
    vector <ll> temp(n,0);
    vector <vector<ll>> vect(n,temp);  
    for(ll i = 0; i < n; i++){
        cin >> str;
        for(ll j = 0; j < n; j++){
            if(str[j] == '0') vect[i][j] = 0;
            else vect[i][j] = 1;
        }
    }

    ll flips = 0;
    ll z = 0, ones = 0, twos = 0;
    for(ll i = 0; i < n/2; i++){
        for(ll j = 0; j < (n+1)/2; j++){
            flips += check2(vect, n, i, j);
        }
    }
    cout << flips << "\n";
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