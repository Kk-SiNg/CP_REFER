#include <bits/stdc++.h>
using namespace std;
int M = 1e9+7;

int power_iterative(int a, int b){
    int product = 1;
    while(b){
        if(b&1) product = (product*a)%M;
        a = (a*a)%M;
        b >>= 1;
    }
    return product;
}
    
//note:- (a^b)%M != (a^(b%M))%M
//also note that power_iterative() function implemented using binary exponiantion has TC = O(lg(b)), so we can have b as large as we want
//but since b can't store anything > 1e18, so we need Euler's Theoram(file:///C:\Users\karti\OneDrive\Desktop\vs_code_1\Number_Theory\Bit_Manupulation\ETF_and_Eulers_theoram.jpeg)
int main(){
    
}