#include <bits/stdc++.h>
using namespace std;

//Q:-given two strings a, b find the length of longest common subsequence in both.
//logic:- first simply write brute for recursion and than meomise.
//Brute force recursion:- think like suppose we are at ith index of a and jth idx of b than think of all possibilities:
//                        1. we can try matching ith and jth char's
//                        2. skip the jth char and then do all these three calls for next j
//                        3. skip the ith char and then do all these three calls for next i

//Tc:- O(n^2) with DP
int dp[1003][1003];
int recur(int i, int j, string &a, string &b){
    if(i < 0 || j < 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int ans =  recur(i-1, j, a, b);     //case-3
    ans = max(ans, recur(i, j-1, a, b));    //case-2
    if(a[i] == b[j]) ans = max(ans, recur(i-1, j-1, a, b)+1);   //case-1
    return dp[i][j] = ans;
}
//feel that recur(i, j) is representing the max length of Longest common subsequence found till i = i, j = j. So this clearly suggests
//that a state of DP/Recursion will be simply dp[i][j]

int main(){
    string a, b;
    cin >> a >> b;
    for(int i = 0; i < 1003; i++){
        for(int j = 0; j < 1003; j++){
            dp[i][j] = -1;
        }
    }
    cout << recur(a.length()-1, b.length()-1, a, b);
}