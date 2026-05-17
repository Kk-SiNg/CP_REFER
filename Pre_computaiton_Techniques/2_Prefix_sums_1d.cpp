//Q---> given Q queries: find sum of elements in given range l,r for given array of size n
//q = 10^4
//n = 10^6

#include <bits/stdc++.h>
using namespace std;
//note loop inside every query will lead to a O(n*q) solution.
//so we will pre-compute sums and solve in O(n) + O(q) solution.

int main(){
    int q, n, a;
    int l, r;
    vector <int> vect;
    cin >> q >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        vect.push_back(a);
    }

    vector <int> prefix_sum;
    prefix_sum.push_back(0);
    for(int i = 0; i < n; i++){
        prefix_sum.push_back(vect[i] + prefix_sum[i]);
    }

    while(q--){
        cin >> l >> r;
        cout << prefix_sum[r] - prefix_sum[l-1] << endl;
    }
}