#include <iostream>
#include <string>
using  namespace std;

int main() {
	string course;
	cout << "what is your course: ";
	cin >> course;
	if (tolower(course[0]) == 'h') {
		cout << "\nyou have applied for a language course!!\n";
	}
	else if (tolower(course[0]) == 'i') {
		cout << "you have a compulsory course\n";
	}
	else {
		cout << "you have applied for a basket course\n";
	}
	return 0;
}