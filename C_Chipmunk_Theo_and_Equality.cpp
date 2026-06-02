#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n, a;
    cin >> n;
    vector <vector<pair<int,int>>> vect(n);  
    for(int i = 0; i < n; i++){
        cin >> a;

        int stp = 0;

        if(a == 1) {vect[i].push_back({a,0}); vect[i].push_back({2,1}); vect[i].push_back({1,2}); continue;}
        vect[i].push_back({a,0});
        while(a != 1){
            stp++;
            if(a%2 == 0) a/=2;
            else a+=1;
            vect[i].push_back({a,stp});
        }
    }

    for(auto it:vect){
        for(pair<int,int> p:it){
            cout << p.first << "->" << p.second << "    ";
        }
        cout << "\n";
    }
    int idx = 0;
    int g_cost = 1e9+1;
    while(true){
        int goal = vect[0][idx].first;
        int ctr = 0;
        int cost = 0;
        for(int i = 0; i < n; i++){
            int j = 0;
            bool f = 1;
            int sz = vect[i].size();
            while(j < sz){
                if(vect[i][j].first == goal) {cost += vect[i][j].second; f = 0; ctr++;break;}
                j++;
            }
            if(vect[i][j].first == 1 && goal == 1 && f) {cost += vect[i][j].second; ctr++;}
        }
        idx++;
        if(ctr >= n) g_cost = min(cost, g_cost);
        // cout << goal << " " << g_cost <<  " " <<  cost << "\n";
        if(idx == vect[0].size()) break;
    }
    cout << g_cost << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}