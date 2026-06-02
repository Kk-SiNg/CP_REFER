#include <bits/stdc++.h>
using namespace std;
#define ll long long

map <int,int> mp = {{1,6}, {6,1}, {3,4}, {4,3}, {2,5}, {5,2}}; 


void solve(){
    int n, a;
    vector <int> vect;  
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        vect.push_back(a);
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(i+1 >= n) break;
        if(mp[vect[i]] == vect[i+1] || vect[i] == vect[i+1]){
            ans++;
            // cout << "i: " << i << "\n";
            i++;
            // cout << "m-i: " << i << "\n";
        }
    }
    cout << ans << "\n";
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