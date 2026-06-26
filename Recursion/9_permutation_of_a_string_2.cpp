#include <bits/stdc++.h>
using namespace std;

//note:- this is an optimisation of previous version, mainly now we don't need hash_map.
//logic:- by swapping elements we can have every possible remaining element at a particular position than shift this window of remaining
//        ele to +1 ans so on until idx == n;

//TC:- O(n!*n), SC = O(lg(n)) ---> auxilary stack.
void permutations(string str, int n, int idx, vector <char> &ds, vector <string> &ans){
    if(idx == n){
        ans.push_back(str);
        return;
    }
    for(int i = idx; i < n; i++){
        swap(str[i], str[idx]);
        permutations(str, n, idx+1, ds, ans);
        swap(str[idx], str[i]);
    }
}

int main(){
    int n;
    cin >> n;
    string str;
    cin >> str;

    vector <char> ds;
    vector <string> ans;
    permutations(str, n, 0, ds, ans);
    for(auto it:ans) {
        for(auto i:it) cout << i << " ";
        cout << "\n";
    }
}