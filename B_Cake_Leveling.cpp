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
    
    int mn = 1e9+1;
    for(int i = 0; i < n-1; i++){
        if(vect[i+1] > vect[i]){
            mn = min(mn, vect[i]);
            cout << mn << " ";
        }
        else{
            
        }
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