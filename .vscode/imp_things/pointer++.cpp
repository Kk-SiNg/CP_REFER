#include <iostream>

using namespace std;


int main(){
    int a = 10;
    int *b = &a;
    for(int i=0; i < 10; i++){
        cout << b + i << endl;
    }
    cout << a << endl << b << endl;
    return 0;
}