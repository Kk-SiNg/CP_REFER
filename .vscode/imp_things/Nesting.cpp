#include <iostream>
#include <vector>

using namespace std;

void print(vector <int> i_th_vector_of_vect) {
	for (int i : i_th_vector_of_vect) {
		cout << i << " ";
	}
	cout << endl;
}

int main() {
	//! Creating a 2-D matrix of n*m
	vector<vector<int>> vect;

	int n, m;
	cout << "what are the dimentions of matrix that you want to give?\n";
	cin >> n >> m;

	for(int i = 0; i < n; i++){
		int b;
		vector <int> temp;       //? this vector is just a template to push back inside 1st vector
		for(int j = 0; j< m; j++){
			cin >> b;
			temp.push_back(b);
		}
		vect.push_back(temp);
	}

	for (int i = 0; i < n; i++) {
		print(vect[i]);
	}

	//! we can also refer to the matrix created, just like a real matrix:
	cout << "2,3 \"indexed\" element of matrix is: " << vect[2][3];

	//! we can create whatever level of nest we want i.e. pair inside vector which is further inside a vector, etc;
	return 0;
}