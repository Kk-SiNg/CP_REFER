// note sometimes it is imp to consider bit by bit, like in this question. We know that if a particular bit of M(i,j) is 1 then
//that means that either ai or aj has to have that bit 1. So first we go through all M(i,j) ans take only the required bits i.e. we
//initialise all the 2^30 bits of all the elements of required 1D array with 1, i.e. 1111...30times. Now to take only the required bits
//from M(i,j), take it's & with ai,aj. DO this for all M(i,j) and use the final array made to do orignal check i.e. wether ai|aj == M(i,j)

#include <bits/stdc++.h>
using namespace std;

long long M = (1<<31)-1;        // a number with all 30 bits toggled on.
void solve(){
    int n, a;
    vector <vector<int>> vect; 
    vector <int> temp;
    cin >> n;
    
    vector <int> check(n, M);
    for(int i = 0; i < n; i++){
        temp.clear();
        for(int j = 0; j < n; j++){
            cin >> a;
            temp.push_back(a);
            if (i == j) continue;
            check[i] &= a;
            check[j] &= a;
        }
        vect.push_back(temp);
    }
    if(n == 1){
        cout << "YES\n2\n";
        return;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i != j && (check[i]|check[j]) != vect[i][j]) {cout << "No\n"; return;}
        }
    }
    cout << "YES\n";
    for(int i:check) cout << i <<" ";
    cout << "\n";
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