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
    int ele = vect[0];
    int ele2 = -1;
    for(int i = 0; i < n; i++){
        if(vect[i] != ele) {ele2 = i+1; break;}
    }
    if(ele2 == -1) {cout << "NO\n"; return;}
    cout << "YES\n";
    for(int i = 1; i < n; i++){
        if(vect[i] == ele) cout << ele2 << " " << i+1 << "\n";
        else cout << 1 << " " << i+1 << "\n";
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