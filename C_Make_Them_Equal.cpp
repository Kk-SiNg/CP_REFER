#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n;
    char ch;
    string str;
    cin >> n >> ch;
    cin >> str;

    bool flg = 0;
    int occ = -1;
    for(int i = 0; i < n; i++){
        if(str[i] != ch) {flg = 1;}
        if(str[i] == ch) occ = i+1;
    }
    if(!flg) {cout << "0\n"; return;}

    if(str[n-1] == ch) cout << "1\n" << n << "\n";
    else if(occ != -1 && n < 2*occ) cout << "1\n" << occ << "\n";
    else{
        cout << "2\n";
        cout << n << " " << n-1 << "\n";
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