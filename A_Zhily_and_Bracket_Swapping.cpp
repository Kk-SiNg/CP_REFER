#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n;
    string a,b;
    cin >> n;
    cin >> a >> b;

    int tolerance = 0, ct = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == ')') ct++;
        if(b[i] == ')') ct++;
        if(i % 2 != 0) tolerance += 2;

        if(ct > tolerance){
            // cout << "1: " << i << "\n";
            // cout << "tolerance: " << tolerance << "   ct: " << ct << "\n";
            cout << "NO\n";
            return;
        }
    }
    tolerance = 0, ct = 0;
    for(int i = n-1; i >= 0; i--){
        if(a[i] == '(') ct++;
        if(b[i] == '(') ct++;
        if(i % 2 == 0) tolerance += 2;

        if(ct > tolerance){
            // cout << "2: " << i << "\n";
            // cout << "tolerance: " << tolerance << "   ct: " << ct << "\n";
            cout << "NO\n";
            return;
        }
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