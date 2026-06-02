#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(int idx, string str, int n, set <string> &ans){
    if(idx == n){
        ans.insert(str);
        return;
    }

    for(int i = idx; i < n; i++){
        swap(str[idx], str[i]);
        solve(idx + 1, str, n, ans);
        swap(str[idx], str[i]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin >> str;
    set <string> ans;
    solve(0, str, str.length(), ans);
    cout << ans.size() << "\n";
    for(string s:ans) cout << s << "\n";
}