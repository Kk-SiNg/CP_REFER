#include <bits/stdc++.h>
using namespace std;

// Q:- given n, the length of array <= 10^6 and k <= 2*10^6 the sum. TASK--->if there exist any
// two *different* elements in array st: a+b == k then print "YES" each ai <= 10^6.

//logic:- note since array is not sorted so binary search will take O(2*n(lgn)) time.
//creating a hash array:- TC:-O(n);
int arr[1000000 + 1] = {0};
int mx = 1e6 + 1;
int main(){
    int n, k, num;
    cin >> n >> k;


    for (int i = 0; i < n; i++){
        cin >> num;
        arr[num] = 1;
    }
    int left = 0, right = mx-1;
    while(!arr[left]) left++;
    while(!arr[right]) right--;

    while(right >= left){
        if(left + right < k) left++;
        else if(left + right > k) right--;
        else{
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}