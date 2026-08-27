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
    if(n%2 == 0){
        int sm = 0;
        for(int i = 1; i < n; i+=2){
            sm += vect[i]-vect[i-1];
        }
        if(sm < 0) no
        else yes
    }
    else yes
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