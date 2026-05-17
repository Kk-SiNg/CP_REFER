#include <bits/stdc++.h>
using namespace std;


//logic ---> make 2 prefix gcd arrays one forward from 0th index to l-1th and other backward array from n-1th to r+1th
//where each next element is gcd till that element

void solve(){
    int n , q;
    cin >> n >> q;
    int a;
    vector <int> vect;
    for(int i = 0; i < n; i++){
        cin >> a;
        vect.push_back(a);
    }

    vector <int> pf_forward(n+1, 0), pf_backward(n+1, 0);

    for(int i = 1; i <= n; i++) pf_forward[i] = (__gcd(vect[i-1], pf_forward[i-1]));
    for(int i = n-1; i >= 0; i--) pf_backward[i] = (__gcd(vect[i], pf_backward[i+1]));


    int l, r;
    while(q--){
        cin >> l >> r;
        cout << __gcd(pf_forward[l-1], pf_backward[r]) << endl;
    }
}


int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}