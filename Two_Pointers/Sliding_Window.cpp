#include <iostream>
#include <vector>

using namespace std;

//<=============================> *Sliding Window* <===========================================================>

//Q1. given an array of int, find the max possible sum of k consucative intigers
int max_sum(vector <int> &vect, int &k){
    int n = vect.size();
    
    int sum = 0, max = 0;
    for(int i = 0; i < k; i++){
        sum += vect[i];
    }
    max = sum;

    int l = 0;
    int r = k-1;
    while (r < n-1){
        sum -= vect[l];
        r++, l++;
        sum += vect[r];

        if(sum > max){
            max = sum;
        }
    }
    return max;
}

//Q2. a. given an array find the length of longest subarray with (sum <= 14):-
/*Tempelate:-
    1st find a solution via brute force.
    2nd try to look for better solution.
    3rd optimise.
*/
//time: O(N^2), space: O(1)
int without_sliding_window(vector <int> &vect, int k){
    //generate all subarrays:
    int subarray_sum;
    int max_length = 0, length;
    for(int i = 0; i < vect.size(); i++){
        subarray_sum = 0;
        length = 0;
        for(int j = i; j < vect.size(); j++){
            subarray_sum += vect[j];
            length+=1;

            if(length > max_length){
                max_length = length;
            }
            if(subarray_sum > k) break;
        }
    }
    return max_length-1;
}

//time: O(2N), space = O(1).
int with_sliding_window(vector <int> &vect, int k){
    int l = 0, r = 0;
    int n = vect.size();
    int sum = 0, max_length = 0;
    while (r < n){
        sum += vect[r];

        while(sum > k){         //shrink down the window till sum reduces to or below k
            sum -= vect[l];
            l++;
        }
        if(max_length > r-l+1){
            max_length = r-l+1;
        }
        r++;                    //expand window
    }
    return max_length;
}
//optimised version: since we only need length so no need to shrink down window till sum <= k, i.e. while loop gone.
//time: O(N), space: O(1).
int with_sliding_window_optimised(vector <int> &vect, int k){
    int l = 0, r = 0;
    int n = vect.size();
    int sum = 0, max_length = 0;
    while (r < n){
        sum += vect[r];

        if(sum > k){         //as soon as sum > k we will shrink down by only 1 so that in next iteration length = max_found_till_now
            sum -= vect[l];
            l++;
        }
        if(max_length > r-l+1){
            max_length = r-l+1;
        }
        r++;                    
    }
    return max_length;
}

//Q3. find the number of subarrays with sum == k.
/*
    method:
        a.      x = number of subarray with sum <= k
        b.      y = number of subarrays with sum <= k-1
        c.      ans = x-y
*/

//Q4. find the shortest subarray given <some_condition> 

int main(){
    //input
    int n, k, a;
    vector <int> vect;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a;
        vect.push_back(a);
    }

    cout << max_sum(vect, k) << endl;
    cout << without_sliding_window(vect,k) << endl;
}