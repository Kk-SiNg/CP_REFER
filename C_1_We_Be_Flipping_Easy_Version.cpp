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
    vector <int> ans;
    bool flg = 0;
    int r = n-1;
    while(r >= 0){
        if(vect[r] > 0)break;
        r--;
    }
    for(int i = r-1; i >= 0; i--){
        if(vect[i] < 0 && !flg) continue;
        else if(vect[i] > 0 && flg) continue;
        ans.push_back(i+1);
        flg ^= 1;
    }
    cout << ans.size()+1 << "\n";
    for(int it:ans) cout << it << " ";
    cout << r+1 << "\n";
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