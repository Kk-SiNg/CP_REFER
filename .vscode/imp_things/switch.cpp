// switch----> 1. similar to if else 2.best for purposes where cases are required and input is given in int form.

#include <iostream>
using namespace std;
    
int main(){
    int pizzabrand;
    cout << "what pizza brand do you wnat\n" << "1:dominos\n" << "2:lapinos\n" << "3:pizza hut\n";
    cin >> pizzabrand;
    switch(pizzabrand){
        case 1:
            cout << "you ordered from dominos\n";
        break;
        case 2:
            cout << "you ordered from lapinos\n";
        break;
        case 3: 
            cout << "you ordered from pizza hut\n";
        break;
        default:
            cout << "dont enter rubbish!\n";
    }
    return 0;

}