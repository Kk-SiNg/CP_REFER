#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n, a;
    vector <int> vect;  
    cin >> n;
    bool flg = 0;

    cin >> a;
    vect.push_back(a);
    for(int i = 1; i < n; i++){
        cin >> a;
        if(a < vect[i-1]) flg = 1;
        vect.push_back(a);
    }
    if(vect[n-1] < vect[n-2]) {cout << "-1\n"; return;}

    if(vect[n-1] < 0){
        if(flg) cout << "-1\n";
        else cout << 0 << "\n";
    }
    else{
        cout << n-2 << "\n";
        for(int i = 0; i < n-2; i++){
            cout << i+1 << " " << n-1 << " " << n << "\n"; 
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