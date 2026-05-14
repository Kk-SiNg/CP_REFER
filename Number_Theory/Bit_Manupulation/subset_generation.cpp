#include <bits/stdc++.h>
using namespace std;

//logics:- 
//1. total number of subsets of a number are 2^n. So we can represent all subsets of a set with cardanality = n using a n-bit binary
//   so simply consider all such subsets from 0 to n-1 and for each mask of a subset check the set bits
//   (note-> that each mask just represent the indices that are taken as set bit and indices omitted = unset_bit).
//TC:- O(n*(2^n))
//note that time complexicity of recursive soln is O(2^n)
void print_subsets(vector <int> vect, int n){
    int set_count = pow(2, n);
    for(int mask = 0; mask < set_count; mask++){
        for(int i = 0; i < n; i++){
            int copy = mask;
            // if(((mask)&(1<<i)) != 0) cout << vect[i] << " ";       //note: both if() are correct
            if(((copy>>i)&1) != 0) cout << vect[i] << " ";
        }
        cout << "\n";
    }
}

int main(){
    int n, a;
    cin >> n;

    vector <int> vect;
    for(int i = 0; i < n; i++){
        cin >> a;
        vect.push_back(a);
    }
    print_subsets(vect, n);
}