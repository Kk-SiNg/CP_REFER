#include <bits/stdc++.h>

using namespace std;

// concept ---> while sorting we will divide the current array into two parts from mid
// then process one of got array, divide it and keep dividing
// until we have only one element in both left and right divisions,
// now comes the merging part of O(n+m) TC(for sorted arrays of size m and n) from bottom to top,
// i.e. initially we will have only one element then 2(sorted array) then 4 or more(sorted) and so on

//note ---> we will not actually divide the array into 2 parts we will have the pointer to start and end of array to be procesed.
// and logically think as first divide -> divide... then merge -> merge...

void merge(vector <int> &vect, int lo, int mid, int hi){
    vector <int> temp;

    int left = lo;
    int right = mid + 1;

    while(left <= mid && right <= hi){      //merge till any one side goes out of bound
        if(vect[left] <= vect[right]){
            temp.push_back(vect[left]);
            left++;
        }
        else{
            temp.push_back(vect[right]);
            right++;
        }
    }

    // merge the numbers left either on left or right sorted half
    while(left <= mid){                     
        temp.push_back(vect[left]);
        left++;
    }
    while(right <= hi){
        temp.push_back(vect[right]);
        right++;
    }

    for(int i = lo; i <= hi; i++){          //update the orignal array
        vect[i] = temp[i-lo];
    }
}

// TC :- O(n*lg(n))
// SC :- O(n)
void merge_sort(int lo, int hi, vector <int> &vect){
    if(lo >= hi) return;

    int mid = (lo + hi)/2;
    merge_sort(lo, mid, vect);          //go all the way to left
    merge_sort(mid+1, hi, vect);        //go to the complementary right child of the left element from bottom to top
    merge(vect, lo, mid, hi);           //start merging when no further division possible.
}

int main(){
    int n, a;
    cin >> n;
    vector <int> vect;
    for(int i = 0; i < n; i++){
        cin >> a;
        vect.push_back(a);
    }
    merge_sort(0,n-1,vect);

    for(int i:vect){
        cout << i << " ";
    }
    cout << "\n";
}