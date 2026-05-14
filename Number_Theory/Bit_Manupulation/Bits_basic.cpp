#include<iostream>

using namespace std;

void printBinary(int a){
    for(int i = 10; i >= 0; i--){       //we first right shift or divide a by pow(2,high_no), then keep reducing this number 1 by 1
        cout << ((a>>i) & 1);
    }
    cout << endl;
}

int main(){
    int a = 13;
    printBinary(a);
    int i = 3;

    // finding if ith position have a set bit
    if((a) & (1<<i)){
        cout << "ith bit is set\n";
    }
    else{
        cout << "bit not set\n";
    }

    //bit set
    printBinary(a | (1<<i));

    //bit unset
    //note---> do "&" with 1111... and all the bits will be preserved.
    printBinary(a & (~(1<<i))); // note---> we wanted all bits to be 1 except that at ith position, so invert the bit with 1 at ith position
    
    //bit toggle
    printBinary(a ^ (1<<i));

    //to count number of set bits simply do a loop or __builtin_popcount() or __builtin_popcountll();

    return 0;
}