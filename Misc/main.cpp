#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n;
    cin >> n;
    int q;
    cin >> q;
    vector <int> vect(n,0);
    for(int i = 0; i < n; i++){
        cin >> vect[i];
    }

    sort(vect.begin(), vect.end());

    while(q--){
        int k;
        cin >> k;
        int lo = 0, hi = n-1;
        while(hi-lo > 1){
            int mid = (hi+lo)/2;
            if(vect[mid] > k) hi = mid-1;
            else lo = mid;
        }
        if(vect[lo] == k) cout << "1YES\n";
        else if(vect[hi] == k) cout << "2YES\n";
        else cout << "NO\n";
    }
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