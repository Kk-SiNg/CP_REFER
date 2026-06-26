#include <bits/stdc++.h>
using namespace std;

//Q. place n queens in a chess board of n*n size, st: no two queens are able to attack each other
//approach:- 1. no two queens can be on same row/column/digonal


//check out images to understand validation policy.
bool is_valid(int column, int i, int n, vector <bool> &left_row, vector <bool> &lower_diagonal, vector <bool> &upper_diagonal){
    if(left_row[i]) return 0;
    if(lower_diagonal[column+i]) return 0;
    if(upper_diagonal[n-1 + column - i]) return 0;

    return 1;
}

void solve(int column, int n, vector <vector<char>> &ds, vector <bool> &left_row, vector <bool> &lower_diagonal, vector <bool> &upper_diagonal){

    if(column == n){
        for(auto it:ds){
            for(char ch:it) cout << ch << " ";
            cout << "\n";
        }
        cout << "\n";
        return;
    }

    for(int i = 0; i < n; i++){
        if(!is_valid(column, i, n, left_row, lower_diagonal, upper_diagonal)) continue;
        ds[column][i] = 'Q';
        left_row[i] = 1;
        lower_diagonal[column+i] = 1;
        upper_diagonal[n-1 + column - i] = 1;
        solve(column+1, n, ds, left_row, lower_diagonal, upper_diagonal);
        ds[column][i] = '.';
        left_row[i] = 0;
        lower_diagonal[column+i] = 0;
        upper_diagonal[n-1 + column - i] = 0;
    }
}






int main(){
    int n;
    cin >> n;

    vector <bool> left_row(n,0);
    vector <bool> upper_diagonal(2*n+1, 0);
    vector <bool> lower_diagonal(2*n+1, 0);

    vector <char> s(n,'.');
    vector <vector<char>> ds(n,s);
    solve(0, n, ds, left_row, lower_diagonal, upper_diagonal);
}