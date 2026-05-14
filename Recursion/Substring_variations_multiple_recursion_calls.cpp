// multiple_recursion_calls means that we will call f() more than once inside f()
#include <bits/stdc++.h>

using namespace std;
//TC :- O(2^n)
//Space :- O(2^n)
int fibonachi(int a){
    if(a <= 1) return a;
    return fibonachi(a-1) + fibonachi(a-2);
}

//TC :- O(2^n)
//SC :- O(n)
void sub_seq_generation(int index, vector <int> current_arr, int n, vector<int> &vect){
    if(index >= n){
        for(int i:current_arr) cout << i << " ";
        cout << endl;
        return;
    }
    current_arr.push_back(vect[index]);
    sub_seq_generation(index+1, current_arr, n, vect);
    current_arr.pop_back();
    sub_seq_generation(index+1, current_arr, n, vect);
}

//TC :- O(2^n)
//SC :- O(n)
void find_all_subarrays_with_sum_k(int index, vector <int> current_arr, int n, vector <int> &vect, int sum, int k){
    if(index >= n){
        if(sum == k) {
            for(int i:current_arr) cout << i << " ";
            cout << endl;
        }        
        return;
    }
    current_arr.push_back(vect[index]);
    sum += vect[index];
    find_all_subarrays_with_sum_k(index+1, current_arr, n, vect, sum, k);
    current_arr.pop_back();
    sum -= vect[index];
    find_all_subarrays_with_sum_k(index+1, current_arr, n, vect, sum, k);
}

//TC :- O(2^n)
//SC :- O(n)
bool find_any_one_subarray_with_sum_k(int index, vector <int> current_arr, int n, vector <int> &vect, int sum, int k){
    if(index >= n){
        if(sum == k) {
            for(int i:current_arr) cout << i << " ";
            cout << "\n";
            return true;
        }
        else return false;
    }
    current_arr.push_back(vect[index]);
    sum += vect[index];
    if (find_any_one_subarray_with_sum_k(index+1, current_arr, n, vect, sum, k)) return true;

    current_arr.pop_back();
    sum-=vect[index];
    if (find_any_one_subarray_with_sum_k(index+1, current_arr, n, vect, sum, k)) return true;

    return false;
}

//TC :- O(2^n)
//SC :- O(n)
int find_the_number_of_subarrays_with_sum_k(int index, int n, vector <int> &vect, int sum, int k){
    if(index >= n){
        if(sum == k) return 1;
        else return 0;
    }

    sum += vect[index];
    int l = find_the_number_of_subarrays_with_sum_k(index+1, n, vect, sum, k);      //check while including this index in sum
    sum -= vect[index];
    int r = find_the_number_of_subarrays_with_sum_k(index+1, n, vect, sum, k);      //check while excluding this index from sum

    return l + r;           //feel that in this recursion we are first doing sum upto extreme of right of array/or if sum == k;
                            // and note that l is carrying the overall found subarrays with sum = k till that step in recursion
}

int main(){
    int n, k;
    cin >> n >> k;
    int a;
    vector <int> vect;
    for(int i = 0; i < n; i++){
        cin >> a;
        vect.push_back(a);
    }
    // cout << fibonachi(n);
    // sub_seq_generation(0, {}, n, vect);
    cout << find_the_number_of_subarrays_with_sum_k(0, n, vect, 0, k);
}