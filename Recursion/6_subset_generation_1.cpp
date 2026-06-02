#include <bits/stdc++.h>
using namespace std;
//Q:- find the sums of all the subsets of given array and print them in ascending order in TC:- O(2^n), SC:- O(n);
//Note:- We know the power_set algo(uses bit masking) can find all subsets in O(2^n*n) with SC:- O(1), also using recursion we can generate
//       power set in O(2^n) and SC:- O(n).

//ans:- this solution is generating subsets in TC:- O(2^n + 2^n(lg(2^n))), SC:- O(2^n) using simple pick-not_pick recursion. and the
//      required solution is actually not possible.

void subset_geneartion(int idx, int sum, vector <int> vect, int n, vector <int> &sums){
    if(idx == n){
        sums.push_back(sum);
        return;
    }

    subset_geneartion(idx+1, sum+vect[idx], vect, n, sums);     //pick
    subset_geneartion(idx+1, sum, vect, n, sums);               //not-pick
}

int main(){
    int n, a;
    cin >> n;
    vector <int> vect;

    for(int i = 0; i < n; i++){
        cin >> a;
        vect.push_back(a);
    }
    
    vector <int> sums;
    subset_geneartion(0, 0, vect, n, sums);
    sort(sums.begin(), sums.end());
    for(int it:sums) cout << it << " ";
    cout << "\n";
}