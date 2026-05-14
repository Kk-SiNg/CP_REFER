#include <iostream>

using namespace std;

double epsilon = 1e-5; //for values upto 4 decimal places

double multiplication(double a, int t){
    double product = 1;
    for(int i = 0; i < t; i++){
        product*=a;
    }
    return product;
}

int main(){
    double n;
    cin >> n;
    double lower = 1, upper = n, mid;
    while(upper-lower > epsilon){
        mid = (upper + lower)/2;

        if(multiplication(mid, 4) > n){
            upper = mid;
        }
        else{
            lower = mid;
        }
    }
    cout << lower << endl;
}