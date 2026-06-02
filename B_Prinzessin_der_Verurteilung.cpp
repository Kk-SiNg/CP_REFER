#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n, a;
    string str;
    cin >> n;
    cin >> str;

    for(char ch = 'a'; ch <= 'z'; ch++){
        bool flg = 1;
        for(char c:str){
            if (c == ch) {flg = 0; break;}
        }
        if(flg) {cout << ch << "\n"; return;}
    }
    for(char ch = 'a'; ch <= 'z'; ch++){
        for(char ch2 = 'a'; ch2 <= 'z'; ch2++){
            bool flg1 = 1;
            for(int i = 0; i < n-1; i++){
                if(str[i] == ch && str[i+1] == ch2) {flg1 = 0;break;}
            }
            if(flg1) {cout << ch << ch2 << "\n"; return;}
        }
    }
    for(char ch = 'a'; ch <= 'z'; ch++){
        for(char ch2 = 'a'; ch2 <= 'z'; ch2++){
            for(char ch3 = 'a'; ch3 <= 'z'; ch3++){
                bool flg1 = 1;
                for(int i = 0; i < n-2; i++){
                    if(str[i] == ch && str[i+1] == ch2 && str[i+2] == ch3) {flg1 = 0;break;}
                }
                if(flg1) {cout << ch << ch2 << ch3 << "\n"; return;}
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}