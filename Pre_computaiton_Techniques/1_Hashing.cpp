#include <iostream>
#include <unordered_map>

using namespace std;

//find how many times a number appeared in an array of size n--> note if this is asked t times then, time:O(N*T)
//but we can actually save frequency of all elements in one n times loop and then fetch it T times, time:O(N + T)


int main(){
/*  
    int n, t, a;
    cin >> n >> t;
    array <int, 10000 + 1> hash = {}; //max value of all elements possible in array is always given in Question.
    for(int i = 0; i < n; i++){
        cin >> a;
        hash[a]++;
    }
    for(int j = 0; j < t; j++){
        cin >> a;
        cout << "frequency: " hash[a] << "\n";
    }
    cout << endl;
    //note---> if max size of int hash_arraay declared in main is 10^5 and globally is 10^6, so if max value of elements in array possible exceeds them then we will use unordered_map.
*/    
    int t, n, a;
    cin >> n >> t;
    unordered_map <int,int> hash_map;

    for(int i = 0; i < n; i++){
        cin >> a;
        hash_map[a]++;                    //now the required size of mp is total number of unique elements
    }

    for(int i = 0; i < t; i++){
        cin >> a;
        cout << "frequency = " << hash_map[a] << endl;
    }

    //note---> Questions may include making hash of characters from a-z or other characters, just use ASCII for this, ex: index of 'b' => int('b' - 'a'). Just think as if we are mapping each available data point to integral countable values.
    return 0;
}