#include <bits/stdc++.h>
using namespace std;

//Q. find the next greatest element of every element i.e. form an array.
//M1. Solve in TC:- O(N^2) if we iterate through each element and then for every element we iterate again from the next of current element
//till greater ele is found.
//M2. Use LIFO property of stack, insert new element till the top < current. If (top < current) => Standing at current value the top ele
//has the closest > current at current and note all the ele below top also have NGE = current.
void NGE(vector <int> vect, int n){
    stack <int> stc;
    unordered_map<int, int> mp;   //we could have used a vector of n size, where ith index holds the NGE of the corresponding value in vect
    for(int i = 0; i < n; i++){
        while(!stc.empty() && stc.top() < vect[i]){
            mp[stc.top()] = vect[i];
            stc.pop();
        }
        stc.push(vect[i]);
    }
    while(!stc.empty()){
        mp[stc.top()] = -1;
        stc.pop();
    }
}

int main(){
    int n;
    cin >> n;
    vector <int> vect;
    int a;

    for(int i = 0; i < n; i++){
        cin >> a;
        vect.push_back(a);
    }
}