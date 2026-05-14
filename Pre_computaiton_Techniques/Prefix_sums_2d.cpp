/*Q:-
given a 2-D array of n*n, assume a smaller square then: given (a,b) as the top left of assumed
square and (c,d) as the bottom right. Find the sum of elements in this square.

Constraints:-
q queries <= 10^5
n <= 10^3
*/

//direct solution of 2 n sized loops inside a loop of Q will be TC:- O(n^2)*O(q) = O(10^11)
//so we will precompute the sum of sub matrices with top left as (1,1) and bottom right as
//the index at which we are saving that sum

#include <bits/stdc++.h>
using namespace std;

int main(){
    int q, n, a, b, c, d, ele;
    cin >> q >> n;
    vector <vector<int>> vect;
    vector <int> temp(n+1,0);
    vector <vector<int>> prefix_sums;
    prefix_sums.push_back(temp);        //adds a boundry of 0's on top
    vect.push_back(temp);

    //O(n^2)
    for(int i = 1; i <= n; i++){
        vector <int> temp;
        temp.push_back(0);              //adds a boundry of 0's on left.
        for(int j = 1; j <= n; j++){
            cin >> ele;
            temp.push_back(ele);
        }
        vect.push_back(temp);
    }

    //O(n^2)
    for(int i = 1; i <= n; i++){
        vector <int> temp(n+1, 0);
        prefix_sums.push_back(temp);
        for(int j = 1; j <= n; j++){
            int sum = vect[i][j] + prefix_sums[i][j-1] + prefix_sums[i-1][j] - prefix_sums[i-1][j-1];
            prefix_sums[i][j] = sum;
        }
    }


    //just for reference:- this is prefix_sums array formed
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            cout << prefix_sums[i][j] << " ";
        }
        cout << endl;
    }

    //O(q)
    //check C:\Users\karti\OneDrive\Desktop\vs code_1\Pre_computaiton_Techniques\explaination_of_summation_between_2_corners.jpeg
    while(q--){
        cin >> a >> b >> c >> d;
        cout << prefix_sums[c][d] - prefix_sums[a-1][d] - prefix_sums[c][b-1] + prefix_sums[a-1][b-1] << endl;
    }
}