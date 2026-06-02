#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector <long long> find_pf(long long n){
    vector <long long> primes;
    long long i = 2;
    while(i*i < n){
        if(n%i == 0){
            primes.push_back(i);
            while(n%i == 0) n/=i;
        }
        i++;
    }
    if(n > 1) primes.push_back(n);
    return primes;
}

void solve(){
    int n, k, a;
    set <int> st;
    vector <int> vect;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a;
        st.insert(a);
    }
    for(int i:st) vect.push_back(i);
    n = vect.size();
    // cout << n << "\n";

    vector <ll> pf = find_pf(k);
    int sz = pf.size();
    if(sz == 1){
        if(n == 1 && k  == vect[0]){
            cout << "1\n" << k << "\n";
            return;
        }
        if(n != k){
            cout << "-1\n";
            return;
        }
        pf.push_back(1ll);
        sz++;
    }

    sort(vect.begin(), vect.end());
    unordered_map <int,int> mp;
    for(auto it:pf){
        int cp = it;
        while(cp <= k){
            int lo = 0, hi = n-1;
            while(hi - lo > 1){
                int mid = (hi+lo)/2;
                if(vect[mid] > cp) hi = mid-1;
                else lo = mid;
            }
            if(vect[lo] != cp && vect[hi] != cp) {
                cout << "-1\n";
                return;
            }
            mp[cp]++;
            // cout  << "cp: " << cp << "\n";
            cp += it;
        }
    }
    if(mp.size() != n){
        // for(auto it:mp) cout << it.first << " ";
        // cout << "\n";
        cout << "-1\n";
        return;
    }
    if(pf[sz-1] == 1 && sz == 2){
        cout << "1\n1\n";
        return;
    }
    cout << sz << "\n";
    for(auto it:pf) cout << it << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}