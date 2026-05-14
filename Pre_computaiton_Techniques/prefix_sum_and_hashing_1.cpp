#include <bits/stdc++.h>
using namespace std;
// Q:- given q queries and an array with all n elements = 0 initially, in each query add k
// to every element in range a to b(inclusive).

//naive solution: TC:- O(q*n)
//prefix sums: TC:- O(n + q)
// logic:- add k at the ath index(taking base 1 array) and -k to the b+1th index and now prefix sum
// array of given array will have k added in given range. So simply add k to the left and -k to the 
// right+1th element q times and then calculate the prefix sums array.
int main(){
    int n, q;
    cin >> n >> q;
    int a, b, k;
    vector <long long> vect(n+1, 0);
    vector <long long> pf(n+1, 0);

    while(q--){
        cin >> a >> b >> k;
        vect[a] += k;
        if(b != n) vect[b+1] -= k;
    }

    for(int i = 1; i <= n; i++){
        pf[i] = vect[i] + pf[i-1];
    }

    long long mx = -1;
    for(long long i:pf) if(i > mx) mx = i;
    cout << mx << endl;

    
}