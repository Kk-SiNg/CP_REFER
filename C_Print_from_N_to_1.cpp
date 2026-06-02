#include <bits/stdc++.h>
using namespace std;
#define ll long long

void recur(int n){
    if(n < 1) return;
    cout << n << " ";
    recur(n-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    recur(t);
    cout << "\n";
}