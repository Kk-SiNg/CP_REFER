#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n, a;
    vector <int> vect;  
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        vect.push_back(a);
    }
    for(int i = 1; i < n; i++) cout << vect[i] << " ";
    cout << vect[0] << "\n";
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