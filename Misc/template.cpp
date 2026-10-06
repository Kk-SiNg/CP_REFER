#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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

//TC: O(1)
bool isPerfectSquareFast(long long n) {
    if (n < 0) return false;
    int h = n & 0xF;
    if (h > 9 || h == 2 || h == 3 || h == 5 || h == 6 || h == 7 || h == 8) {
        return false; 
    }
    long long root = std::round(std::sqrt(n));
    return (root * root == n);
}

/**
 * Compresses an array by summing adjacent elements that share the same sign,
 * resulting in an array of alternating positive and negative sums. 
 * If a clump's sum becomes exactly 0, it absorbs the next element and takes its sign.
 * @param dir: 0 for Left-to-Right traversal, 1 for Right-to-Left.
 */
template<typename T>
vector<T> clump_signs(const vector<T>& arr, int dir = 0) {
    vector<T> store;
    if (arr.empty()) return store;
    auto process = [&](T x) {
        if (store.empty()) {
            store.push_back(x);
            return;
        }
        T last = store.back();
        if ((last > 0 && x > 0) || (last < 0 && x < 0) || last == 0) 
            store.back() += x;
        else 
            store.push_back(x);
    };
    if (dir == 0) {
        for (int i = 0; i < arr.size(); i++) process(arr[i]);
    } 
    else {
        for (int i = (int)arr.size() - 1; i >= 0; i--) process(arr[i]);
    }
    return store;
}

//provide 2-d vect and val to fill
void fill_2d(vector <vector<int>> &arr, int value_to_fill){
    int rows = arr.size();
    int cols = arr[0].size();
    arr.assign(rows, vector<int>(cols, value_to_fill));
}

//finding total number of inversions in array
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
long long countInversionsPBDS(const vector<int>& b) {
    ordered_set pbds;
    long long inversions = 0;
    for (int i = b.size() - 1; i >= 0; i--) {
        inversions += pbds.order_of_key(b[i]);
        pbds.insert(b[i]);
    }
    return inversions;
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