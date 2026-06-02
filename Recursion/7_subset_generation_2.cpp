#include <bits/stdc++.h>
using namespace std;

//Q:- given an array that may contain duplicate elements, find all the subsets of array without any duplicats.
//M1:- Simply generate all subsets using pic/non-pick recursion and store them in set(TC increase by a factor of log(m)) i.e. 2^n*m*lg(m) 
//M2:- Doing a looping recursion call(TC:- O(n^2*n)) for details refer:-(file:///C:\Users\karti\Desktop\CPP_Refer\Recursion\5_combination_sums_2.cpp)

void non_duplicate_set_generation(int idx, vector <int> &vect, int n, vector <int> ds, vector <vector<int>> &ans){
    ans.push_back(ds);                                  //note we could have added a return condition when idx == n, but for loop will
                                                        //not be executed so automatically return. 
    for(int i = idx; i < n; i++){
        if(i!=idx && vect[i] == vect[i-1]) continue;
        ds.push_back(vect[i]);
        non_duplicate_set_generation(i+1, vect, n, ds, ans);
        ds.pop_back(); 
    }
}


int main(){
    int n, a;
    cin >> n;
    vector <int> vect;

    for(int i = 0; i < n; i++){
        cin >> a;
        vect.push_back(a);
    }
    sort(vect.begin(), vect.end());

    vector <int> ds;
    vector <vector<int>> ans;
    non_duplicate_set_generation(0, vect, n, ds, ans);
}