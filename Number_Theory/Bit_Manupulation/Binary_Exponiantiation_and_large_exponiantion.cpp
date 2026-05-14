//Q:- find the pow(a, b)

#include <iostream>

using namespace std;
int M = 1e9 + 7;

//M1:- simply multiply a, b times in O(n) time.
//M2:- BInary exponiantion--->recursive_method this method is like divide and conquore, i.e. we are using the top element on stack to build
// the next. Full process:- 
// eventually  we will reach the condition when our stack looks like:- f(0), f(1)...and other terms depend upon
// odd/even, So return values will be like 1->a->a^2/a^3 depending on parity...
// 
//TC:- O(lg(b))
int power_recursive(int a, int b){
    if(b == 0) return 1;

    int smart_save = power_recursive(a,b/2);
    if(b&1 == 1){
        return a*smart_save*smart_save;
    }
    else{
        return smart_save*smart_save;
    }
}

// M3:- Binary exponiantion--->iterative_method(find the mod of pow(a,b) wrt M)
// logic:- b can be represented in binary of size log(n) of base 2; i.e. large numbers like 128 can be represented with just 7bits 
// TC:- O(log(b))
int power_iterative(int a, int b){
    int product = 1;
    while(b){
        // feel that we are actually trying to build b from its very first bit, like if b = 13 = 1101, then we will use 2^0, 2^2, 2^3 
        // numbers as powers of a(i.e. a^(2^0 + 2^2 + 2^3)).
        if(b&1){    
            product = (product*a)%M;
        }
        b >>= 1;
        a = (a*a)%M;
    }
    return product;
}
//================================================    Large Exponiantion     ==================================================================================
// note:- as a <= 1e9 and M <= 1e9 hence no problem of overflow but if :- 
//1. a <= 1e18, just change the data types to long long, sice for every "a" or "product" the final stored result is always <=M
//   (cuz we took %M), hence the value of any of the products never exceed 1e18.
//2. M <= 1e18, problem---> now the values of "a" and "product" can go to max of 1e18 and when we do a*a or product*a in next iteration
//   then overflow. Solution:- suppose we need to calculate a*a(a = 1e18), then we will add a+a+a+a......+a(a-times) and take mod at every
//   step.
//   M1. simple loop b-times for a*b
int brute_multiplyer(long long a, long long b){
    long long ans = 0;
    while(b--) ans += a, ans %= M;
}
//   M2. using binary exponintion
int binary_multiplyer(long long a, long long b){
    long long ans = 0;
    while(b){
        if((b&1)) ans = (ans+a)%M;
        a = (a+a)%M;
        b = b>>1;
    }
    return ans;
}
// now use this mutiplyer in binary_exponiantion() function in place of a*a, and product*a.
// check out large_exponiantion when b<= 1e18(file:///C:\Users\karti\OneDrive\Desktop\vs_code_1\Number_Theory\Bit_Manupulation\large_exponiantion_with_ETF_and_Eulers_Theoram.cpp)
int main(){
    
    cout << "recursive solution: " << power_recursive(2,7);     //note we could have use pow() function which returns a double value, but double is not reliable.
    cout << "\niterative solution(to be prefered): " << power_iterative(2,6); 
}