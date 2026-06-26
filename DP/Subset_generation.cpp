#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5 +1;
vector <int> dp(N,-1); 
bool recur(int idx, int sum, int n, vector <int> &vect){

    if(sum < 0) return 0;
    else if(sum == 0) return 1;
    if(idx < 0) return 0;
    
    sum -= vect[idx];
    if(recur(idx+1, sum, n, vect)) return 1;
    sum += vect[idx];
    if(recur(idx+1, sum, n, vect)) return 1;
}



void solve(){
    int n, k, a;
    vector <int> vect;  
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a;
        vect.push_back(a);
    }
    cout << recur(0, k, n, vect);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while(t--){
        solve();
    }
}