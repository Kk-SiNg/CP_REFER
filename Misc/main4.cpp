#include <bits/stdc++.h>

using namespace std;

vector <int> vect;
int n, f, a;
bool is_succesfull_distrubution(int mid){
    
}

int   main(){
    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        cin >> n >> f;
        f+=1;

        for(int j = 0; j < n; j++){
            cin >> a;
            vect.push_back(a);
        }
        sort(vect.begin(), vect.end());

        int lo = 0, hi = 1e4, mid;
        while(hi-lo > 1){
            mid = (hi + lo)/2;
            if (is_succesfull_distrubution(mid)) lo = mid;
            else hi = mid - 1;
        }
        
            
    }
}