#include <iostream>
#include <vector>

using namespace std;

void printBinary(int a){
    for(int i = 10; i >= 0; i--){       //we first right shift or divide a by pow(2,high_no), then keep reducing this number 1 by 1
        cout << ((a>>i) & 1);
    }
    cout << endl;
}

int main(){int a = 13;
    //suppose we are to take input of fruits in  2 diff arrays and then find the comman ones.

    int basket1 = 0, basket2 = 0;
    int b1, b2;
    cin >> b1 >> b2;
    int fruit;

    for(int i = 0; i < b1; i++){
        cin >> fruit;               //we are toggling on the bits corresponding to the number(pre assigned to fruit)
        basket1 = basket1|(1<<fruit);
    }
    for(int i = 0; i < b2; i++){
        cin >> fruit;               
        basket2 = basket2|(1<<fruit);   //note that numbering of fruits should start from 1 and total number of fruits can't exceed 32bits(int) and 64bits(for ll int)
    }
    cout << basket1 << " " << basket2 << "\n";
    cout << "number of common fruits: " << __builtin_popcount(basket1&basket2) << "\n";

//=========================================================================================================================
    //Workers example(see onenote):
    int number_of_workers;
    int available_days;
    int x, max;
    int temp_binary;
    vector <int> mask;
    pair<int, int> worker_pair;

    cin >> number_of_workers;
    for(int i = 0; i < number_of_workers; i++){
        cin >> available_days;
        temp_binary = 0;
        max = 0;
        
        for(int j = 0; j < available_days; j++){
            cin >> x;
            temp_binary = temp_binary|(1<<x);
        }
        mask.push_back(temp_binary);
    }

    //now using this stored data to find max common days pair. time = O(N^2)
    for(int i = 0; i < number_of_workers; i++){
        for(int j = i+1; j < number_of_workers; j++){
            int intersection = mask[i] & mask[j];
            if(intersection > max){
                max = intersection;
                worker_pair = {i,j};
            }
        }
    }

    cout << "max common days: " << __builtin_popcount(max) << " worker pair: " << worker_pair.first << " " << worker_pair.second << endl;
}