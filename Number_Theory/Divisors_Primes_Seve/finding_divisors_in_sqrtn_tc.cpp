//finding divisors in _/n 

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    int i = 1;
    while(i*i <= n){            // note as i reach sqrt(n) => numbers start repeating in pairs.
        if(n%i == 0){
            cout << i << " ";
            if(n/i != i) cout << n/i << " ";
        }
        i++;
    }
}