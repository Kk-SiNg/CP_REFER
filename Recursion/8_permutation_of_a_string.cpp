#include <bits/stdc++.h>
using namespace std;

//Q:- Print all the permutations of an array with discrete elements.
//ans:- 1. total number of ways = n!
//      2. so simply maintain a hash_map carrying the info that a certain element is used or not, then for every recursion loop n times
//         looking for non-visited ele, and picking/not-picking them.

//TC:- O(n!*n*lg(n)), SC = O(2*n). note lg(n) can be avoided by hashing

void permutations(string str, int n, vector <char> &ds, unordered_map<char,bool>&hash, vector <vector<char>> &ans){
    if(ds.size() == n){
        ans.push_back(ds);  //no return required, auto return
    }
    for(int i = 0; i < n; i++){
        if(hash.find(str[i]) != hash.end() && hash[str[i]]==1) continue;
        ds.push_back(str[i]);
        hash[str[i]] = 1;
        permutations(str, n, ds, hash, ans);
        ds.pop_back();
        hash[str[i]] = 0;
    }
}
//note this checking of hash_map technique will fail if we have {repeated elements}, for that use 2nd approch of swapping.

int main(){
    int n;
    cin >> n;
    string str;
    cin >> str;

    vector <char> ds;
    unordered_map<char, bool>hash;
    vector <vector <char>> ans;
    permutations(str, n, ds, hash, ans);
    for(auto it:ans) {
        for(auto i:it) cout << i << " ";
        cout << "\n";
    }
}