#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
int n = 1e6;
vector <bool> vect(n+1, 1);
vector <int> hpf(n+1, 0); // hpf = highest prime factor, this vector will store hpf of every number from 1 to n
vector <int> lpf(n+1, 0);
//Tc = O(n*lg(lg(n)))
void sieve_to_find_lpf_and_hpf_of_n(){
    vect[0] = 0, vect[1] = 0;
    lpf[0] = 0, lpf[1] = 1;
    hpf[0] = 0, hpf[1] = 1;
    for(int i = 2; i <= n; i++){
        if(vect[i]) lpf[i] = i, hpf[i] = i;
        if(vect[i] == true){
            for(int j = i*2; j <= n; j+=i){
                vect[j] = 0;
                hpf[j] = i;                     // just mark j with latest prime that can divide j
                if(lpf[j] == 0) lpf[j] = i;     //only mark for the first time
            }
        }
    }
}


// O(lg(n))
void find_div(int num){
    unordered_map<int, int> mp;

    while(num > 1){         //we will divide num by one of it's prime factors until num is reduced to 1 and we can get lpf or hpf of current num by simple precomputed array.
        int div = hpf[num];
        while(num % div == 0){
            mp[div] ++;
            num /= div;
        }
    }

    for(auto it:mp){
        cout << it.first << " " << it.second << endl;
    }
}

int main(){
    int num;
    cin >> num;
    sieve_to_find_lpf_and_hpf_of_n();
    find_div(num);
}