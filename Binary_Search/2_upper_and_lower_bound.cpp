#include <bits/stdc++.h>

using namespace std;


int upper_bound(vector <int> &vect, int n, int k){
    int lo = 0, hi = n-1;
    int mid;

    while(hi-lo > 1){
        mid = (lo + hi)/2;
        if(mid >= k){
            hi = mid - 1;
        }
        else{
            lo = mid;
        }
    }
    if(vect[lo] >= k) return lo;        //note--->upper_bound function returns the lowest value > k, hence first check for low
    else if(vect[hi] >= k) return hi;
    else return -1;
}

int lower_bound(vector <int> &vect, int n, int k){
    int lo = 0, hi = n-1;
    int mid;

    while(hi-lo > 1){
        mid = (lo+hi)/2;
        if(vect[mid] > k){
            hi = mid-1;
        }
        else{
            lo = mid;
        }
    }
    if(vect[lo] >= k) return lo;        //note--->lower_bound function returns the lowest value >= k, hence first check for low
    else if(vect[hi] >= k) return hi;
    else return -1;
}

int main(){
    int n, k, a;
    cin >> n >> k;
    vector <int> vect;
    for(int i = 0; i < n; i++){
        cin >> a;
        vect.push_back(a);
    }

    cout << lower_bound(vect, n, k) << endl;
    cout << upper_bound(vect, n, k) << endl;

}