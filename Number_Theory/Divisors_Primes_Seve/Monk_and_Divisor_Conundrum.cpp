//Q. Given an integer array A of size N, Monk needs you to answer T queries for him. In each query, he gives you 2 integers P and Q.
//In response to each of these queries, you need to tell Monk the count of numbers in array A. that are either divisible by P, Q, or both.
//Constraints:-   1 <= n,A[i],T,p,q <=2*1e5


//soln:- construct a hash array for number of elements divisible by i(2 to 2*1e5) that are present in our orignal vect;
#include <bits/stdc++.h>
using namespace std;

vector <int> divisor_count(2*1e5+1, 0);
//TC:- N(lg(N)); N = 2*1e5
void seive(vector <int> vect, int n){
    divisor_count[1] = n;
    for(int i = 2; i <= 2*1e5; i++){
        int count = 0;
        for(int j = i; j <= 2*1e5; j+=i){
            count += vect[j];
        }
        divisor_count[i] = count;
    }
}

int main(){

    int n, a;
    cin >> n;
    vector <int> vect(2*1e5+1, 0);
    for(int i = 0; i < n; i++){
        cin >> a;
        vect[a]++;
    }
    seive(vect, n);
    long long q, r, t;
    cin >> t;
    
    while(t--){
        cin >> q >> r;

        int exclusion_factor = 0;
        if(q*r/(__gcd(q,r)) <= 2*1e5) exclusion_factor = divisor_count[q*r/(__gcd(q,r))];

        cout << divisor_count[q] + divisor_count[r] - exclusion_factor << endl;
    }
}