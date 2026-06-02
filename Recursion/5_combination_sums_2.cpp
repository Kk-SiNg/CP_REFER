#include <bits/stdc++.h>
using namespace std;

//Q:- From a given array choose elements in lexographical order to form subsequences with sum == k.
//note:-  lexographical => no duplicate subsequence and also we need to sort array(see later).
//logic:- we'll have a sorted vect, then loop on it, call recursion for only those elements that are unique in current window(idx--->n),
//        window logic -> for lexographical order of ele in a subsequence we can't choose previous ele in a sorted array(hence did sorting)
//        unique ele logic -> to avoid duplicates
// so what we essentially did was to look at all the i's that were above idx and if that i(vect[i] <= target && it must not have been used
// previously in this stage) is valid we considered it in ds, and moved on, and obviously this ele will be removed and next will be
// considerd once we are returned to previous node.
vector <vector<int>> ans;
void combination_sums(int idx, int target, vector<int>&vect, int n, vector<int>ds){
    if(idx >= n){
        if(target == 0) ans.push_back(ds);
        return;
    }

    for(int i = idx; i < n; i++){
        if(i>idx && vect[i] == vect[i-1]) continue;     //don't call recursion for same value element for which recur is already called
        if(vect[i] > target) break;                     //vect already sorted so anything above i will be > vect[i]
        ds.push_back(vect[i]);
        combination_sums(i+1, target-vect[i], vect, n, ds);
        ds.pop_back();
    }
}

int main(){
    int n, k, a;
    cin >> n >> k;
    vector<int> vect;
    for(int i = 0; i < n; i++){
        cin >> a;
        vect.push_back(a);
    }
    sort(vect.begin(), vect.end());
    combination_sums(0,k,vect,n,{});
    for(vector <int> it: ans){
        for(int i:it){
            cout << i << " ";
        }
        cout << endl;
    }
}