#include <bits/stdc++.h>

using namespace std;

/*LOGICS:-
1. in any subarray either left or right half is always sorted. 
So check in sorted half for element to be found and if not found 
then new search space is other half.
*/

//TC = O(lg(n))
int no_duplicate_element_index_return(vector <int> vect, int n, int k){
    int lo = 0, hi = n-1, mid;
    while(hi - lo > 1){
        mid = (hi+lo)/2;
        //sorted left
        if(vect[lo] <= vect[mid]){      //note if this condition is met then this half is sorted
            if(vect[lo] <= k && vect[mid] >= k) hi = mid;       
            else lo = mid+1;
        }
        //sorted right
        else{
            if(vect[mid] <= k && vect[hi] >= k) lo = mid;
            else hi = mid-1;
        }
    }
    if(vect[hi] == k) return hi + 1;
    else if(vect[lo] == k) return lo + 1;
    else return -1;
}

//note ---> we can't find the exact indices of required element using BS but we can state if it is present or not. 
//TC may go to O(n/2)
bool duplicate_elements_present(vector <int> vect, int n, int k){
    int lo = 0, hi = n-1, mid;
    while(hi - lo > 1){
        mid = (hi+lo)/2;

        //if left, mid and right elements are equal then we can't compare to say which half is sorted
        //so simply shrink down search by 1 unit form left and right until we find atleast 1 diff element
        //rest all logic remains same
        if(vect[lo] == vect[mid] && vect[mid] == vect[hi]){
            lo ++, hi--;
            continue;
        }

        //sorted left
        if(vect[lo] <= vect[mid]){      //note if this condition is met then this half is sorted
            if(vect[lo] <= k && vect[mid] >= k) hi = mid;       
            else lo = mid+1;
        }
        //sorted right
        else{
            if(vect[mid] <= k && vect[hi] >= k) lo = mid;
            else hi = mid-1;
        }
    }
    if(vect[hi] == k) return true;
    else if(vect[lo] == k) return true;
    else return false;
}


//logic we will pick up the min element from sorted half which is just lo for left and mid for right
//sorted, then simply consider other unsorted half which may have even a lower value.
// TC :- O(lg(n))
// SC :- O(1) 
// note ---> if it's asked that how many times the array is rotated, then index of min is simply the ans.
int find_min_ele_in_rotated_sorted_array(vector <int> vect, int n){
    int lo = 0, hi = n-1, mid, ans = 1e8;
    while(hi - lo > 1){
        mid = (hi+lo)/2;

        //left sorted:-
        if(vect[lo] <= vect[mid]){
            ans = min(ans, vect[lo]);
            lo = mid + 1;
        }
        //right sorted:-
        else{
            ans = min(vect[mid], ans);
            hi = mid - 1;
        }
    }
    ans = min(vect[hi], ans);
    ans = min(vect[lo], ans);
    return ans;
}


int main(){
    int n, a, k;
    cin >> n >> k;
    vector <int> vect;

    for(int i = 0; i < n; i++){
        cin >> a;
        vect.push_back(a);
    }
    cout << find_min_ele_in_rotated_sorted_array(vect, n);
}