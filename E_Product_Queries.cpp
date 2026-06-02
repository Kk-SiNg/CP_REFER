#include <bits/stdc++.h>
using namespace std;
#define ll long long


int N = 3e5+5;
vector <bool> primes(N+1,1);    //all indices filled with 1
//Tc = O(n*lg(lg(n)))
void sieve_to_find_all_primes_till_n(){
    primes[0] = 0, primes[1] = 1;
    for(int i = 2; i <= N; i++){
        if(primes[i] == true){
            for(int j = i*2; j <= N; j+=i){
                if(j%i == 0) primes[j] = 0;
            }
        }
    }
}

void solve(){
    int n, a;
    cin >> n;
    vector <bool> vect(n+1,0);  
    for(int i = 0; i < n; i++){
        cin >> a;
        vect[a] = 1;
    }
    
    for(int i = 1; i <= n; i++){
        if(primes[i]){
            if(vect[i]) cout << 1 << " ";
            else cout << "-1 ";
        }
        else cout << "a ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    sieve_to_find_all_primes_till_n();
    while(t--){
        solve();
    }
}