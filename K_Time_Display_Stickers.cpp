#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll find1(array<ll, 10> &arr, ll n){
    for(ll i = n; i >= 0; i--){
        // if(i == 1) continue;
        if(arr[i] > 0){
            arr[i]--;
            return i;
        } 
    }
    return -1;
}
ll find2(array<ll, 10> &arr, ll n){
    for(ll i = n; i >= 0; i--){
        if(arr[i] > 0){
            arr[i]--;
            return i;
        } 
    }
    return -1;
}

bool c1(array <ll, 10> &arr){
    ll f0 = find2(arr, 1);
    ll f1 = find2(arr, 1);
    ll f2 = find2(arr, 5);
    ll f3 = find2(arr, 9);
    if(f0 == -1 || f1 == -1 || f2 == -1 || f3 == -1){
        if(f0 != -1) arr[f0]++;
        if(f1 != -1) arr[f1]++;
        if(f2 != -1) arr[f2]++;
        if(f3 != -1) arr[f3]++;
        return 0;
    }
    return 1;
}
bool c2(array <ll, 10> &arr){
    ll f0 = find1(arr, 0);
    ll f2 = find1(arr, 5);
    ll f1 = find1(arr, 9);
    ll f3 = find1(arr, 9);
    if(f0 == -1 || f1 == -1 || f2 == -1 || f3 == -1){
        if(f0 != -1) arr[f0]++;
        if(f1 != -1) arr[f1]++;
        if(f2 != -1) arr[f2]++;
        if(f3 != -1) arr[f3]++;
        return 0;
    }
    return 1;
}


void solve(){
    ll n, a;
    string str;
    cin >> n;
    cin >> str;
    array <ll, 10> arr = {0};
    for(char ch:str){
        // cout << ch-'0' << " ";
        arr[ch - '0']++;
    }
    array <ll, 10> arr2 = arr;
    // cout << "\n";

    ll ans1 = 0;
    while(c1(arr)) ans1++;
    // cout << "ans1: " << ans1 << " ";
    while(c2(arr)) ans1++;
    // cout << ans1 << "\n";
    
    ll ans2 = 0;
    while(c2(arr2)) ans2++;
    // cout << "ans2: " << ans2 << " ";
    while(c1(arr2)) ans2++;
    // cout << ans2 << "\n";

    cout << max(ans1, ans2) << "\n";
    // cout << "\n";
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