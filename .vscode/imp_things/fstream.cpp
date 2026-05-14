#include <iostream>
#include <string>
#include <fstream>                      //🔍 What's Going On:
                                        //std::ofstream is a class provided by the C++ Standard Library (from the <fstream> header).

                                       // When you writ:-
                                        // ofstream file(...);
                                        // you are creating an object named file from the class ofstream.

using namespace std ;

int edit(string username);

void signup(){
    string username;
    int pin;
    cout << "\nusername-";
    cin >> username;
    cout << "\n6 digit pin-\n";
    cin >> pin;
    ofstream file(username + ".txt", ios::app);       // create a new file or open existing, ios::app make sure that new items added do not replace previous text but apeend new one
    file << username << endl;                         // outputing username into file.
    file << pin;
    file.close();                                      // close is a method of the object file.

}
string login(){
    string username;
    string trueusername;
    int pin;
    int truepin;
    
    cout << "enter username\n";
    cin >> username;
    ifstream file(username + ".txt");
    file >> trueusername;                    // taking input from file to our variable.
    if(trueusername == username){
        cout << "enter pin\n";
        cin >> pin;
        file >> truepin;
        if(truepin == pin){
            string response;
            cout << "login successfull!" << endl;
            cout << "do you want to add food items(yes or no)" << endl;
            cin >> response;
            if(tolower(response[0]) == 'y'){                //this line gets the first char of response and lowers it.
                edit(username);
            }
            else{ 
                return username;
            }
        }
        else{
            cout << "wrogn pin\n";
            return "";
        }
    }
    else{
        cout << "invalid username\n";
        return "";
    }
}

//int main(){
//    cout << "HELLOW! I WILL HELP YOU TO TRACK YOUR DAILY FOOD INTAKE.\n";
//    cout << "press 1 to login and 2 to signup\n";
//    int response;
//    cin >> response;
//
//    if(response == 1){
//        string username = login();
//
//        if(username == ""){
//            return 0;
//        }
//        else{
//            ifstream file(username + ".txt", ios :: app);
//            int line = 1;
//            string food;
//
//            // while(file.eof() == 0){        // loop iterates until end of file is reached which return 1
//            //     file >> food;              // if file is not closed then we will grab next item present in file every next time.
//            //     if(line > 2){
//            //         cout << food << endl;
//            //     }
//            //     line++;
//            // }
//
//            // while(file.eof() == 0){
//            //     if (line > 2){
//            //         getline(file, food);      // we grab next line from file and put it into food starting with 1st line.
//            //         cout << food << endl;
//            //     }
//            //     line++;
//            // }
//
//            while(file >> food){
//                if (line > 2){
//                    cout << food << endl;
//                }
//                line ++;
//            }   
//
//
//        }
//    }
//    if (response == 2){
//       signup();
//    }
//
//   
//    
//    return 0;
//}


int edit(string username){
    string food;
    cout << "what did you eat today!" << endl;
    cin >> food;
    ofstream file(username + ".txt", ios::app);
    file << food << endl;
    file.close();

    return 0;
}