#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate_spiral(int n) {
    // Handle edge case for n <= 0 to prevent crashes
    if (n <= 0) return {};

    // Initialize an n x n grid with 0
    vector<vector<int>> grid(n, vector<int>(n, 0));
    
    // CORRECTED: Both r and c must use (n - 1) / 2 for perfect centering
    int r = (n - 1) / 2;
    int c = (n - 1) / 2;
    
    // Movement vectors: Right, Down, Left, Up
    int dr[] = {0, 1, 0, -1};
    int dc[] = {1, 0, -1, 0};
    
    int val = 0;
    grid[r][c] = val++;
    
    int step_size = 1;
    int direction = 0; // Start by moving Right
    
    // Simulate the spiral walk
    while (val < n * n) {
        // The step size repeats twice
        for (int i = 0; i < 2; ++i) {
            for (int step = 0; step < step_size; ++step) {
                // Stop once we've placed all n^2 elements
                if (val >= n * n) {
                    return grid;
                }
                
                // Move to the next cell
                r += dr[direction];
                c += dc[direction];
                
                // Assign the value
                grid[r][c] = val++;
            }
            // Turn 90 degrees clockwise
            direction = (direction + 1) % 4;
        }
        // Increase the step size after two turns
        step_size++;
    }
    
    return grid;
}

void solve() {
    int n;
    cin >> n;
    
    vector<vector<int>> ans = generate_spiral(n);
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t; // Read number of test cases if required by the problem
    while (t--) {
        solve();
    }
    
    return 0;
}