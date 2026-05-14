#include <bits/stdc++.h>
using namespace std;

//TC:- O(n*lg(n))
//logic:- while traversing through given array suppose i'am standing at a position i than i will have the prefix sums till before this ith
//ele now note:- our plan is to find all subarrays that include this ith element(eventually i will vary from 0 to n-1) and have sum == k,
//so their is only one possibility---> that if some subarray before i have sum = prefix_sums_till_i - k(use binary search in prefix_sums)
//or the whole subarray have the sum == k.
int longest_subarray_with_sum_k_for_both_positive_and_negatives(vector <int> vect, int n, int k){
    unordered_map<long long, int> mp;   //to store prefix_sum, index
    int sm = 0;
    int mx_len = 0;
    for(int i = 0; i < n; i++){
        sm += vect[i];
        if (mp.find(sm) != mp.end()) mp[sm] = i;    //note:- if that sum already exist in map then no need to add it cuz the current
                                                    //ith ele is surely 0 and since max length is asked hence we stick to the older index
        if(sm == k) mx_len = max(mx_len, i+1);
        else{
            if(mp.find(sm - k) != mp.end()) mx_len = max(mx_len, i-mp[sm-k]);
        }
    }
    return mx_len;
}



//note:- for (including positive and 0 numbers only) we can use simple two pointer in O(2N) by expanding and shrinking window
int main(){
    int n, a, k;
    cin >> n >> k;
    vector <int> vect;

    for(int i = 0; i < n; i++){
        cin >> a;
        vect.push_back(a);
    }
}