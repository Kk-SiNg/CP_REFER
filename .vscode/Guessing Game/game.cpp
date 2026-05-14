#include <iostream>
#include <string>
#include "game.hpp"

using namespace std;

string game(int trials_left, int correct_number) {
	int gaussed;
	while (trials_left > 0) {
		cout << "you have " << trials_left << " trials left\n";
		trials_left--;
		cout << "what is your guess\n";
		cin >> gaussed;
		if (correct_number++ == gaussed) {
			return "Congratulations you won!";
		}
		else {
			cout << "wrong guess\n";
		}
	}
	return "you lost";
}