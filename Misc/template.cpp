#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define sort_vect(c) sort(c.begin(), c.end())
#define endl "\n"
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define nl cout << "\n";

const int MOD = 1e9 + 7;
const int INF = 1e18;

//bits
void PB(int a){
    for(int i = 10; i >= 0; i--){ 
        cout << ((a>>i) & 1);
    }
    cout << endl;
}
// Function to left rotate vector by k positions
void leftRotate(std::vector<int>& vec, int k) {
    if (vec.empty()) return;
    k = k % vec.size(); // handle large k
    std::rotate(vec.begin(), vec.begin() + k, vec.end());
}

// Function to right rotate vector by k positions
void rightRotate(std::vector<int>& vec, int k) {
    if (vec.empty()) return;
    k = k % vec.size(); // handle large k
    std::rotate(vec.begin(), vec.end() - k, vec.end());
}

bool isPerfectSquareFast(long long n) {
    if (n < 0) return false;

    // Fast O(1) filtering using a lookup bitmask for hexadecimal endings
    // Perfect squares can only end in 0, 1, 4, or 9 in base 16
    int h = n & 0xF; // Equivalent to n % 16
    if (h > 9 || h == 2 || h == 3 || h == 5 || h == 6 || h == 7 || h == 8) {
        return false; 
    }

    // Only compute the hardware square root if it passes the filter
    long long root = std::round(std::sqrt(n));
    return (root * root == n);
}

template<typename T>
vector<T> clump_signs(const vector<T>& arr, int dir = 0) {
    vector<T> store;
    if (arr.empty()) return store;
    // Helper lambda to process each element cleanly
    auto process = [&](T x) {
        if (store.empty()) {
            store.push_back(x);
            return;
        }
        T last = store.back();
        //clump if both positive, both negative, or current sum is 0
        if ((last > 0 && x > 0) || (last < 0 && x < 0) || last == 0) store.back() += x;
        else store.push_back(x);
    };
    // dir == 0: Left to Right
    // dir == 1: Right to Left
    if (dir == 0) {
        for (int i = 0; i < arr.size(); i++) process[arr[i]];
    } 
    else {
        for (int i = (int)arr.size() - 1; i >= 0; i--) process(arr[i]);
    }
    return store;
}




int topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x));}
int lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x));}

void solve(){
    int n, e;
    vector <int> vect;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> e;
        vect.push_back(e);
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}