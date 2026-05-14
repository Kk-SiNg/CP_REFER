#include <iostream>
#include <string>
#include <cstdlib>          // For random number generation and much more....
#include <ctime>            // to use time.
#include "game.hpp"
using namespace std;


string game(int trials_left, int correct_number){

    int gaussed;
    // for(trials_left; trials_left > 0; trials_left--){

    //     cout << "you have " << trials_left << " trials left\n";
    //     cout << "what is your guess\n";
    //     cin >> gaussed;
    //     if(correct_number  == gaussed){
    //         return "Congratulations you won!";
    //     }
    //     else {
    //         cout << "wrong guess\n";
    //     }
    // }
    // return "you lost";
    // }
    
    
    
    while (trials_left > 0){
        cout << "you have " << trials_left << " trials left\n";
        trials_left-- ;
        cout << "what is your guess\n";
        cin >> gaussed;
        if(correct_number++  == gaussed){
            return "Congratulations you won!";
        }
        else {
            cout << "wrong guess\n";
        }
    }
    cout << correct_number;
    return "you lost";

}

//int main(){
//    cout << "GUESSING GAME \"GUESS BETWEEN 1 TO 20\" \n";
//    int ranking;
//    cout << "what is your ranking out of 10\n"; 
//    cin >> ranking;
//
//    srand(time(NULL));   //it seeds the rand generator and time(null) works as a seed which is diff every time as it provides current time in seconds
//// null tells to simply return the current time without storing it.  
//    int correct = (rand() % 20)+1; // assign a random number between 0 to 19 to correct
//
//    if(ranking < 1){
//        cout << "your ranking should be between 1 to 10\n";
//    }
//    else if(ranking <= 5){
//        cout << "you get 10 trials\n";
//        cout << game(10, correct);
//    }
//    else if(ranking < 7){
//        cout << "you get 5 trials\n";
//        cout << game(5, correct);
//
//    }
//    else if(ranking <= 10){
//        cout << "you get 3 trials\n";
//        cout << game(3, correct);
//
//    }
//    else{
//        cout << "your ranking should be between 1 to 10\n";
//    }
//
//    return 0;
//}
//
