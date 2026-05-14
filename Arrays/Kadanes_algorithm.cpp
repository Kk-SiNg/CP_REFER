//Q. given an array(both positives and negatives) find the longest subarray with the max sum
#include<bits/stdc++.h>
using namespace std;


//Logic:- keep two pointers l,r; l pointing to start of a subarray and r the current position now the update rule for l is as:- always
//        track for max subarray(l to r) as we increase r in every iteration, now as soon as the sum of this subarray drops <= 0 we have
//        a fresh start from l = r+1.
int main(){
    int n, a;
    cin >> n;
    vector <int> vect;
    for(int i = 0; i < n; i++){
        cin >> a;
        vect.push_back(a);
    }

    int l = 0, r = 0;
    int sum = 0, mx = -1e8;
    int start, end;
    while(r < n){
        sum += vect[r];
        if(sum <= 0){
            l = r+1;
            sum = 0;
        }
        if(sum > mx){
            mx = sum;
            start = l, end = r;
        }
        r++;
    }
    cout << mx << endl;
    cout << "start: " << l+1 << "\nend: " << end+1 << endl; 

}