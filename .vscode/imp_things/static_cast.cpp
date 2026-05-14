#include <iostream>
#include <string>
using namespace std;

int main(){
   int a;
   a = getchar();
   cout << a << endl; //outputs int corresponding to char
   cout <<  static_cast<char>(a) ; //converts int to char using ascee table
   return 0;

}