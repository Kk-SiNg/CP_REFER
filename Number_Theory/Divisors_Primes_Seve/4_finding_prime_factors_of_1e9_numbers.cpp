#include <bits/stdc++.h>
using namespace std;

//Q. find the prime factors of n = 1e16;
//problem:- suppose we found all the factors of n in sqrt(n) TC but still we would need to check that if a number between 1-n, which is a
//          factor, is a prime number or not. For this we can use sieve but sieve for n = 1e9+ is not possible in 1sec.
//logic:- 1. start from 2 till sqrt(n), so starting with 2 divide n by 2 until it is no longer divisible, than by 3, than by 4... now
//           note that since we divided by 2 multiple times than it is impossible that the leftover-n is div. by 4, so we can say that if 
//           leftover-n is div by current i than i is a prime number and also a prime factor.
//        2. Note that we can't have more than 1 number greater than sqrt(n) which is a prime-factor:- assume that p1*k1, p2*k2 are two
//           diff combinations =n, where p1,p2 are primes >sqrt(n) and k1,k2 < sqrt(n), than p1*p2 has to divide n, but since their
//           product > n hence contradiction.
//        3. Using (2), if the number leftout at the end is >1 than it is also prime.

vector <long long> find_pf(long long n){
    vector <long long> primes;
    long long i = 2;
    while(i*i < n){
        if(n%i == 0){
            primes.push_back(i);
            while(n%i == 0) n/=i;
        }
        i++;
    }
    if(n > 1) primes.push_back(n);
    return primes;
}


int main(){
long long n;
    cin >> n;

    vector <long long> primes = find_pf(n);
    for(long long i:primes) cout << i << " ";
    cout << "\n";
}