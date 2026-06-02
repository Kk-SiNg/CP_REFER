#include <bits/stdc++.h>
using namespace std;


void f(int i, string str){
    if(i >= str.length()/2){
        cout << "palandrome\n";
        return;
    }
    if(str[i] != str[str.length()-i-1]) {
        cout << "not a palandrome\n";
        return;
    } 
    f(i+1, str);
}



int main(){
    int q;
    cin >> q;
    string str;
    while(q--){
        cin >> str;
        f(0,str);
    }
}