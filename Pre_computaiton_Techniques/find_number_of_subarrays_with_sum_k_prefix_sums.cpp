#include <bits/stdc++.h>
using namespace std;

// tc:- O(n*lg(n))
// logic:- same as longest_subarry_with_sum_k where k can be +ve,-ve,0 except that in place of carrying the oldest index for the occurance of a sum
// we'll carry the number of occurances of a sum

int count_number_of_subarrays(vector <int> vect, int n, int k){
    unordered_map <long long, int> mp;

    long long sm = 0;
    int counter = 0;
    mp[0] = 1;                  //for conditions where (sm - k == 0)
    for(int i = 0; i < n; i++){
        sm += vect[i];
        mp[sm] ++;
        if(mp.find(sm-k) != mp.end()) counter+=mp[sm-k];//think opposite:- if sum == k, starting at some mid or whatever element, say x times, than
                                                    //their has to be sum == sm - k exactly x times from starting so simply check for sm-k
    }
    return counter;
}



int main(){
    int n, k, a;
    cin >> n >> k;
    vector <int> vect;

    for(int  i = 0; i < n; i++){
        cin >> a;
        vect.push_back(a);
    }
    cout << count_number_of_subarrays(vect, n, k) << endl;
}