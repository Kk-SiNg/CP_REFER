// Q:- find all combinations of given array having sum of elements == k.


//first of all in combination sums order of elements chosen doesn't matter(like in subarray sums)
/* logic:- 
We will repeat the same thing again and again i.e. we will give chance to every element
of being chosen in contributing to sum, note:-whether to repeat choosing same element depends on Q.
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

void combination_sums(int index, int target, vector <int> vect, vector <int> temp_Array){
    if(index == vect.size()){               //note since we are considering every possible 
        //combinations here, like choosing 0th index until target < 0, then moving one step up in
        //recursion tree and then calling same function for next index then choosing this index
        // until target is exausted and so on, hence suppose taking 0th index 5 time made
        // target == 0, now we will consider next index, ingnore it, then next and again ignore
        // till index == n; that is why base condition is reaching n

        if(target == 0){
            ans.push_back(temp_Array);
        }
        return;
    }

    if(target > 0){
        temp_Array.push_back(vect[index]);      //index chosen to contribute
        combination_sums(index, target-vect[index], vect, temp_Array); //if same element was not allowed more than once then simply do index+1 here
        temp_Array.pop_back();  // remove the element to consider the case of not chosen this index
    }
    combination_sums(index+1, target, vect, temp_Array);
}

int main(){
    int n, k, a;
    cin >> n >> k;
    vector<int> vect;
    for(int i = 0; i < n; i++){
        cin >> a;
        vect.push_back(a);
    }

    combination_sums(0,k,vect,{});
    for(vector <int> it: ans){
        for(int i:it){
            cout << i << " ";
        }
        cout << endl;
    }


}