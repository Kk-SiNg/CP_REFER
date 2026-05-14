#include <iostream>

using namespace std;

void printBinary(int n){
    for(int i = 10; i >= 0; i--){
        cout << ((n >> i) & 1);
    }
    cout << endl;

}

int main(){
    int a = 58;
    printBinary(a);
    int i = 2;

    //even/odd
    //(note ---> first bit of all even number is 0 and that of odd number is 1)
    if(a&1 == 1){
        cout << "odd\n";
    }
    else{
        cout << "even\n";
    }
    
    //multiply/divide
    printBinary(a>>1); //div
    cout << (a>>1) << endl;

    //clear all MSB's till a given index:
    printBinary(a&(1<<(i) - 1));

    //clear all LSB's till a given index:
    printBinary(a&(~((1<<(i+1))- 1)));

    //finding if given number is power of 2:
    if(a & (a-1) == 0){
        cout << "power of 2\n";
    }

    // XOR: 1. Swapping numbers
    int i1 = 4, i2 = 9;
    i1 = i1^i2;
    i2 = i2^i1;
    i1 = i1^i2;
    cout << "i1: " << i1 << " i2: " << i2 << "\n";

    //finding missing number from an array containing all numbers except one
    int n = 6;
    int arr[n] = {1,2,5,6,3};
    int record1 = 0;
    int record2 = 0;
    for(int i = 0; i < n; i++){     //time = O(n)
        record1 = record1 ^ (i+1);
        record2 = record2 ^ arr[i];
    }
    cout << (record1 ^ record2) << endl;

    //given an array with all enteries occuring even number of times, find it?
    int ans = 0;
    int x;
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> x;
        ans ^= x;
    }
    cout << ans << "\n";
}