#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>

using namespace std;

int find_min(vector <int> &vect, int n){
    int min = 1e9;
    for(int i = 0; i < n; i++){
        if (vect[i] < min){
            min = vect[i];
        }
    }
    return min;
}

//Q1. from a DECK OF CARDS pick k card, in a turn you can pick 1 card from bottom or top. Find max sum of numbers written on cards possible
//logic:- you can access next card from top/bottom only if you have accessed previous card
int Card_Problem(vector <int> &vect, int k){

    int n = vect.size();
    int max_sum = 0;
    int l_sum = 0, r_sum = 0;
    for(int i = 0; i < k; i++){
        l_sum += vect[i];
    }
    int r_index = n-1;
    max_sum = l_sum;

    for(int i = k-1; i >= 0; i--){
        l_sum -= vect[i];
        r_sum += vect[r_index];
        r_index--;
        max_sum = max(r_sum+l_sum, max_sum);
    }

    return max_sum;
}

//Q2. given a string find the longest substring with no repeating characters, find the max length possible.
//M1(brute force, time:O(N^2))
int longest_substring_without_repeating_character_Brute_force(string str, int n){
    int max_len = 0;
    for(int i = 0; i < n; i++){
        int hashh[256] = {0};    //a hash array of size 256, i.e. all possible char covered.
        int length = 0;
        for(int j = i; j < n; j++){
            if(hashh[str[j]] == 1) break;
            length++;
            hashh[str[j]] = 1;
        }
        if(length > max_len) max_len = length;
    }
    return max_len;
}
//M2(2 pointer, time: O(N))
//logic:- we will store last occurances of characters
int longest_substring_without_repeating_character_two_pointer(string str, int n){
    int l=0, r=0;
    int hash[256] = {-1};   //to store last occurance of a character
    int max_length = 0; 

    while(r < n){
        if(hash[str[r]] >= l){
            l = hash[str[r]] + 1;
        }
        max_length = max(r-l+1, max_length);
        hash[str[r]] = r;
        r++;
    }
    return max_length;
}

//Q3. find the longest *length* of subarry with consucative 1's given that it is allowed to flip atmost k 0's.
//M1(brute force: time:O(N^2)) ---> simply generate all possible subarrays checking that number of 0's shouldn't exceed k
//M2(two pointer: time(O(2N)))
int find_longest_1_array_with_at_most_k_zeroes(string str, int n, int k){
    int l = 0, r = 0;
    int zeroes = 0;
    int max_length = 0;
    while(r < n){
        if(str[r] == '0') zeroes++;
        while(zeroes > k){
            if(str[l] == '0') zeroes--;
            l++;
        }
        max_length = max(r-l+1, max_length);
        r++;
    }
    return max_length;
}
//M3(optimisation: time(O(N)))
int find_longest_one_array_with_at_most_k_zeroes(string str, int n, int k){
    int l = 0, r = 0;
    int max_len = 0;
    int zeroes = 0;
    while(r < n){
        if(str[r] == '0') zeroes++;
        if(zeroes > k){             //logic ---> we actually don't need to shrink down lesser than already found max_length
            if(str[l] == 0){
                zeroes--;
            }
            l++;
        }
        else max_len = max(max_len, r-l+1);
    }
    return max_len;
}

//Q4. Find the max number of fruits that can be selected continuously, given that you have 2 baskets and each basket can contain
//    only a single type of fruit
//M1(brute force:- generate all possible subarrays) time: O(N^2)
int max_fruits_brute_force(vector <int> vect, int n){
    int max_fruits = 0;

    for(int i = 0; i < n; i++){
        set <int> st;
        for(int j = i; j < n; j++){
            st.insert(vect[j]);
            if(st.size() > 2) break;
            max_fruits = max(max_fruits, j-i+1);
        }
    }
    return max_fruits;
}
//M2(optimised): O(2N)
int max_fruits_optimised(vector<int> vect, int n){
    int max_fruits = 0;
    unordered_map <int,int> hash;
    int l = 0, r = 0;
    
    while(r < n){
        int len = 0;
        hash[r]++;
        while(hash.size() > 2){         //to reduce the time complexixity to O(N) simply remove while with "if" and if size is > 2 then
                                        //do not shrink down completely just move the constant window.
            hash[l]--;
            if(hash[l] == 0) hash.erase(l);
            l++;
        }
        max_fruits = max(max_fruits, r-l+1);
        r++;
    }
    return max_fruits;
}

//Q5. find total number of subsets including atleast 1 unit of every character involved.
//M1(brute force--->just find every subarray and use a hash map to check in time:O(N^2))
//M2(optimal), time:O(N^2)
int max_subsets_with_all_given_char(){
    string str = "abcdbac";
    int n = 7;
    int k = 4;    //total diff characters, every of these char need to be included in substring
    int r = 0;
    int max_count = 0;
    unordered_map <char, int> hash;

    //logic:- while standing at every character we will see the minimal window that covers set of all elements in str and then everything
    //to the left of min last occuring number (including the min last occuring index itself) will be all subsets corresponding while
    //standing at the rightmost element.
    while(r<n){
        hash[str[r]] = r;           //store the last occurance of characters encountered yet
        if(hash.size() == k){
            vector <int> for_min_occurance;
            for(auto i:hash) for_min_occurance.push_back(i.second);
            max_count += find_min(for_min_occurance, for_min_occurance.size()) + 1;
        }
        r++;
    }
    return max_count;
}

//Q6. given a string having char from A-Z find the max length of a substring with all same characters, given that you can change
//    any k characters to any other char.
//M1(brute force) time:O(N^2)
int max_substring_all_char_same(string str, int n, int k){
    int max_length = 0;
    for(int i = 0; i < n; i++){
        int hash[26] = {0};
        int max_frequency = 0;
        for(int j = i; j < n; j++){
            hash[str[j] - 'A']++;
            max_frequency = max(max_frequency, hash[str[j]]);   //logic: for any substring we'll have the most frequent occuring
                                                                //element's frequency and then min changes req = length - max_frequency
            int changes = n-i+1 - max_frequency;
            if(changes <= k){
                max_length = max(max_length, j-i+1);
            }
        }
    }
    return max_length;
}
//M2(two pointer) time:O(2N*26)
int max_substring_all_char_same_optimal(string str, int n, int k){
    int l = 0, r = 0, max_length = 0, changes, max_frequency = 0;
    int hash[26] = {0};

    while(r < n){
        hash[str[r]-'A']++;
        max_frequency = max(max_frequency, hash[str[r]-'A']);
        changes = r-l+1 - max_frequency;

        while(changes > k){
            hash[str[l] - 'A']--;
            l++;
            max_frequency = 0;
            for(int i = 0; i < 26; i++){
                max_frequency = max(max_frequency, hash[i]);
            }
            changes = r-l+1 - max_frequency;
        }
        max_length = max(max_length, r-l+1);
        r++;
    }
    return max_length;
}

//Q7. given an array find the number of subarrays with sum == k, given that each element in array is positive
//TC:- O(2n)
int number_of_subarrays_with_sum_k_positives_only_element(vector <int> vect, int n, int k){
    int counter = 0;
    int r = 0, l = 0, sum = 0;
    while(r < n){
        sum += vect[r];
        while(sum > k){
            sum -= vect[l];
            l++;
        }
        if(sum == k) counter++;
        r++;
    }
    return counter;
}

//Q7. given a binary array find the number of subaarays with sum == k
//logic:-
//1. if we are allowed to use O(n) space than a simple prefix_sums approch will do as we have 0's, but to optimise space to O(1)
//   we will use two pointer but note that this approch is only valid for binary strings.
//2. (sum == k) = (sum <= k) - (sum <= k-1)
//3. for sum <= k it is easy cuz suppose l is at some place and r is at some other place and sum == k than r-l+1 will simply represent 
//   all subarrays with sum<=k that *involve the element at r*; repeat this process for all r<n
int number_of_subarrays_with_sum_equal_to_k_binary_Array(vector <int> vect, int n, int k){
    int counter_k = 0;
    int counter_k_minus_1 = 0;
    int l = 0, r = 0, sum = 0;
    while(r < n){
        sum += vect[r];
        while(sum > k){
            sum -= vect[l];
            l++;
        }
        if(sum == k) counter_k += r-l+1;
        r++;
    }
    l = 0, r = 0, sum = 0;
    if(k-1 >= 0){
        while(r < n){
            
            sum += vect[r];
            while(sum > (k-1)){
                sum -= vect[l];
                l++;
            }
            if(sum == (k-1)) counter_k_minus_1 += r-l+1;    //involve all subarrays with sum<=k including ele at rth index
            r++;
        }
    }
    return counter_k - counter_k_minus_1;
}
//note-> more questions on binary subarrays can be framed like:- find the number of subarrays with the sum of odd elements == k...

//Q8.find the number of subarrays with exactly k distinct intigers.
//logic:-   1. k_distinct_ele = (<= k distinct ele) - (<= k-1 distint_ele)
//          2. we will use map to store frequencies of elements encountered till current position of "r" if number of ele in map is > size
//             then we'll start shrinking, covering all values of r.

void subarray_with_k_distinct_ele(vector <int> vect, int n, int k){
    unordered_map <int, int> mp;
    int l = 0, r = 0;
    int ctr_k = 0;
    int ctr_k_minus_1 = 0;
    //solving for <=k ele
    while(r < n){
        mp[vect[r]]++;
        while(mp.size() > k){
            mp[vect[l]]--;
            if(mp[vect[l]] <= 0) mp.erase(vect[l]);
            l++;
        }
        ctr_k += r-l+1;
        r++;
    }
    //solving for <=k-1 ele
    r = 0, l = 0;
    mp.clear();
    while(r < n){
        mp[vect[r]]++;
        while(mp.size() > k-1){
            mp[vect[l]]--;
            if(mp[vect[l]] <= 0) mp.erase(vect[l]);
            l++;
        }
        ctr_k_minus_1 += r-l+1;
        r++;
    }
}

//Q9. given a string str and another string a, find the minimum window present in str containing all characters of a in any order.
//M1:- go through all subarrays in O(n^2) and check if current subarray has allcharacters of a via hash array of size 256 covering all char
//M2:- two pointers and hash_map--->maintain a pre-initialised map containing all ele of a. while fix l = 0, and move until a valid
//     substring is found(maintain a ctr to count number of ele of a covered with exact frequency) now start shrinking till ctr <= a.len
//     repeat process till r < n
//TC:- O(2n)
void find_min_str_containing_window(string str, string a){
    int n = str.length();
    int m = a.length();
    int l = 0, r = 0;
    int ctr = m;
    int starting_idx = -1, min_len = 1e7+5;
    unordered_map <char, int> mp;

    for(int i = 0; i < m; i++){
        mp[a[i]]++;
    }
    while(r < n){
        if(mp.find(str[r]) != mp.end()) mp[str[r]]--;
        if(mp.find(str[r]) != mp.end() && mp[str[r]] >= 0) ctr++;

        while(ctr == m){
            if(mp.find(str[l]) != mp.end()) mp[str[l]]++;
            if(mp[str[l]] > 0) {
                min_len = r-l+1;
                starting_idx = l;
                ctr--;
            }
            l++;
        }
    }
}

int main(){
    int n, k, a;
    cin >> n >> k;
    vector <int> vect;
    for(int i = 0; i < n; i++){
        cin >> a;
        vect.push_back(a);
    }

    cout << number_of_subarrays_with_sum_k_positives_only_element(vect, n, k) << endl;

}