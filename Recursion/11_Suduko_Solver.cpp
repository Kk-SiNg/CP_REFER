#include <bits/stdc++.h>
using namespace std;

bool is_valid(int row, int column, int i, int n, vector<vector<int>>board){
    //validate row
    for(int c = 0; c < n; c++){
        if(board[row][c] == i) return 0;
    }
    //validate column
    for(int r = 0; r < n; r++){
        if(board[r][column] == i) return 0;
    }
    //vaidate box
    for(int r = (row/3)*3; r < (row/3)*3 + 3; r++){
        for(int c = (column/3)*3; c < ((column/3)*3) + 3; c++){
            if(board[r][c] == i) return 0;
        }
    }
    return 1;
}


void solve(int row, int n, vector <vector <int>> &board){
    if(row == n){
        for(auto it:board){
            for(auto i:it) cout << i << " ";
            cout << "\n";
        }
        cout << "\n";
        return;
    }

    for(int column = 0; column < n; column++){
        if(board[row][column] == -1){
            for(int i = 1; i <= n; i++){
                if (!is_valid(row, column, i, n, board)) continue;
                board[row][column] = i;
                solve(row+1, n, board);
                board[row][column] = -1;
            }
        }
    }
}


int main(){
    int n = 9, a;
    vector <int> row(n, -1);
    vector <vector <int>> board(n, row);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a;
            board[i][j] = a;
        }
    }
    solve(0, n, board);
}