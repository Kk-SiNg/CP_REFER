#include <bits/stdc++.h>
using namespace std;

//Q. you are given a 8*8 chess board and starting, ending points for a knight(chess) in t queries find the min possible moves taken to reach the
//   target. Represent x-axis(columns) with a,b,c..., y-axis(rows) with '1','2','3'...
//logic:- feel BFS like spreading from a node in all four directions following given constraints(knight's). So we will follow knight's path
//        while pushing child nodes to current node in queue.
int N = 1e5 + 5;
int visited[8][8];
int levels[8][8];

vector <pair<int,int>> directions = {
    {2,1}, {2,-1},
    {-2,1}, {-2,-1},
    {1,2}, {-1, 2},
    {1,-2}, {-1,-2}
};

bool is_valid(int x, int y){
    if(x < 0 || x >= 8) return 0;
    if(y < 0 || y >= 8) return 0;
    return 1;
}
int get_x(char c) {return(c-'a');}
int get_y(char c) {return(c-'1');}

void reset(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            visited[i][j] = 0, levels[i][j] = 0;
        }
    }
}

void solve(){
    int x1, y1, x2, y2;
    cin >> x1 >> y1;
    cin >> x2 >> y2;

    queue <pair<int, int>> q;
    q.push({x1,y1});
    visited[x1][y1] = 1;

    while(!q.empty()){
        int x_top = q.front().first, y_top = q.front().second;
        q.pop();
        for(int i = 0; i < 8; i++){
            int x = x_top + directions[i].first, y = y_top + directions[i].second;
            if(!is_valid(x,y)) continue;
            if(!visited[x][y]){
                q.push({x,y});
                visited[x][y] = 1;
                levels[x][y] = levels[x_top][y_top] +1;
            }
            if(x == x2 && y == y2){
                reset();
                cout << levels[x][y] << "\n";
                return;
            }
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}