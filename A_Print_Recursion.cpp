#include <bits/stdc++.h>
using namespace std;
#define ll long long

void recur(int t){
    if(t < 1) return;
    cout << "I love Recursion" << "\n";
    recur(t-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    recur(t);
}