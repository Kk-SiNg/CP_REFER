#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n;
    string a, b;
    cin >> n;
    cin >> a >> b;

    vector<int> allowed;
    int ones = 0, zeroes = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == '0') zeroes++;
        else ones++;
        if(ones == zeroes) allowed.push_back(i);
    }

    // for(int i:allowed) cout << i << "  ";
    // cout << "\n";
    bool flip = 0;
    for(int r = n-1; r >= 0; r--){
        if(((a[r])^flip) == b[r]) continue;
        
        if(allowed.size() == 0) {cout << "NO\n"; return;}
        int lo = 0, hi = allowed.size()-1;
        while(hi - lo > 1){
            int mid = (hi+lo)/2;
            if(allowed[mid] <= r) lo = mid;
            else hi = mid-1;
        }
        // cout << r << "\n";
        if(allowed[lo] != r && allowed[hi] != r) {cout << "NO\n"; return;}
        // cout << r << "\n";
        flip ^=1;
    }
    cout << "YES\n";
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