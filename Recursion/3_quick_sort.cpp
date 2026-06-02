#include <iostream>
#include <vector>

/*
logic :-
first choose a pivot suppose we are choosing pivot as the first or the vect element at lo position
of current array, then put this pivot at it's correct position i.e. all smalls on left and all bigs
on right, repeat this for array on left of pivot, right of pivot until their is only 1 element in left
or right divisions(array).
*/

using namespace std;


int partition(vector <int> &vect, int lo, int hi){
    int i = lo;
    int j = hi;
    int pivot = vect[lo];
    while(i < j){
        while(vect[i] <= pivot && i <= hi) i++; //find the first element greater than pivot from left
        while(vect[j] >  pivot && j >= lo+1) j--; //find the first element smaller than pivot from right
        if (i < j) swap(vect[i], vect[j]);        //as soon as i > j then j will strictly point to the first element from right that is
        // smaller than pivot i.e. if we swap pivot with jth index than everyting on left is smaller and everything on right is greater
    }   
    swap(vect[lo], vect[j]);
    return j;
}

void quick_sort(vector <int> &vect, int lo, int hi){

    if(lo >= hi) return;

    int partition_index = partition(vect, lo, hi);
    quick_sort(vect, lo, partition_index - 1);
    quick_sort(vect, partition_index + 1, hi);
}


int main(){
    int n, a;
    cin >> n;
    vector <int> vect;
    for(int i = 0; i < n; i++){
        cin >> a;
        vect.push_back(a);
    }

    quick_sort(vect, 0, n-1);

    for(int i:vect){
        cout << i << " ";
    }
    cout << endl;
}