#include <bits/stdc++.h>
using namespace std;

//Q. given T<=10 test cases, each test case contains a string of size n <= 10^5 & q queries <= 10^5
//each query contains 2 int a, b <= n; for each query find if it is possible to rearrange the ele...
//of string in range l to r st: formed substring in l to r(inclusive) is a palandrome.

/* LOGICS:-
    1.  if their is autonomy to rearrange elements then if substring have more than 1 odd occurance
        of it's ele... then palindrome not possible.
    2. naive soln:- TC:- O(t*n*q)
    3. prefix_sums + hashing:- TC:-O(t*(n+q))
*/

int main(){
    int t, q, n;
    string s;
    cin >> t;
    int l, r;

    while(t--){
        cin >> q >> n;
        cin >> s;
        vector <int> temp (n+1, 0);
        vector<vector<int>> vect(26, temp); // a 2-D array with each 1-d array corresponding to each alphabet, like vect[4][0] is the record that is there 'a' present in s at 4th position(1 based) 

        for(int i = 0; i < n; i++){
            vect[i+1][s[i] - 'a']++;
        }

        for(int alpha = 0; alpha < 26; alpha++){
            for(int i = 1; i <= n; i++){
                vect[i][alpha] += vect[i-1][alpha];
            }
        }

        while(q--){
            cin >> l >> r;
            int odd_ct = 0;
            for(int i = 0; i < 26; i++){
                if((vect[r][i] - vect[l][i]) % 2 != 0) odd_ct++;
            }
            if(odd_ct > 1) cout << "NO\n";
            else cout << "YES\n";
        }
    }
}