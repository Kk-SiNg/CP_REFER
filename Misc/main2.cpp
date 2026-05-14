#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n, h, k, a;
    vector <int> vect;
    vector <int> l_max(n,0);
    vector <int> r_max(n,0);
    int sum = 0;

    cin >> n >> h >> k;
    int mx = 0;
    for(int i = 0; i < n; i++){
        cin >> a;
        if(a > mx) mx = a;
        l_max[i] = mx;
        vect.push_back(a);
        sum += a;
    }

    mx = 0;
    for(int i = n-1; i >= 0; i--){
        if(vect[i] > mx) mx = vect[i];
        r_max[i] = mx;
    }
    
    int ans = 0;
    if(sum % h == 0) {cout << (sum/h)*(n) + (sum/h -1)*k << "\n"; return;}
    else ans = (sum/h)*(n+k);

    int target = h%sum;
    cout << "target: " << target << "\n";
    cout << "ans: " << ans << "\n";
    int comp = 0;
    cout << target << " is target\n";
    for(int i = 0; i < n; i++){
        comp += vect[i];
        if(l_max[i] < r_max[i]){
            if(comp - l_max[i] + r_max[i] > target){
                cout << ans+i+1 << "\n";
                return;
            }
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