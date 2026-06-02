#include <bits/stdc++.h>
using namespace std;
#define ll long long

void print_binary(int num){
    for(int i = 10; i >= 0; i--){
        cout<<((num>>i)&1);
    }
    cout << "\n";
}

void solve(){
    ll n, a;
    vector <ll> vect;
    cin >> n;
    for(ll i = 0; i < n; i++){
        cin >> a;
        // print_binary(a);
        vect.push_back(a);
    }

    ll save;
    for(ll j = 57; j >= 0; j--){
        bool z = 0, o = 0;
        for(ll it:vect){
            if(((it>>j)&1)) o = 1;
            else z = 1;
        }
        if((o&z)) save = j;
    }
    cout << (1ll<<(save+1ll)) << "\n";
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