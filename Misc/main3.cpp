#include <bits/stdc++.h>

using namespace std;

vector <long long int> vect;
long long int n, c;

bool is_dist_safe(int mid){
    int l = 0, r = 0;
    int cows_to_place = c-1;
    while(r < n){
        if((vect[r] - vect[l]) >= mid){
            l = r;
            cows_to_place--;
        }
        if(cows_to_place == 0) return true;
        r++;
    }
    return false;
}

int main(){
    int t;
    cin >> t;
    long long a;

    for(int i = 0; i < t; i++){
        vect.clear();
        cin >> n >> c;
        for(int j = 0; j < n; j++){
            cin >> a;
            vect.push_back(a);
        }
        sort(vect.begin(), vect.end());
        
        long long lo = 0, hi = 1e9, mid;
        while(hi - lo > 1){
            mid = (hi + lo)/2;
            if(is_dist_safe(mid)) lo = mid;
            else hi = mid-1;
        }
        if(is_dist_safe(hi)) cout << hi << endl;
        else cout << lo << endl;
    }
}