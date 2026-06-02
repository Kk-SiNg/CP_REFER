#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n, k;
    cin >> n >> k;
    if(n%2 == 0){
        k %= (n+1);
        cout << k << "\n";
    }
    else{
        int a = n/2;
        cout <<  +1<< "\n";
    }
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