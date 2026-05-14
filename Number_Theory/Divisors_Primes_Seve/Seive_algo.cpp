#include <iostream>
#include <vector>

using namespace std;

/*logic ---> 1st assume that all numbers from 2 to n are prime then iterate throught each number
like take initially 2, make all other numbers divisible by 2 as false, then go to next number
and note that if number is prime then and only then it will survive till it is reached...
*/
int n;
vector <bool> vect(n+1,1);    //all indices filled with 1
//Tc = O(n*lg(lg(n)))
void sieve_to_find_all_primes_till_n(){
    vect[0] = 0, vect[1] = 0;
    for(int i = 2; i <= n; i++){
        if(vect[i] == true){
            for(int j = i*2; j <= n; j+=i){
                if(j%i == 0) vect[j] = 0;
            }
        }
    }
}

int main(){
    cin >> n;
    sieve_to_find_all_primes_till_n();
    for(int i = 0; i <= n; i++){
        cout << vect[i] << " ";
    }
    cout << endl;
}