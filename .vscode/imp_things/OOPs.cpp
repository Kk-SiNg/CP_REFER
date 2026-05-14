#include <iostream>
#include <string>

using namespace std;

class Lense{

    private:
    float refractive_index;
    float R1;
    float R2;

    public:
    float refractive_index_left;
    float refractive_index_right;

    static float my_priscription;                    //static datamembers belong to class and can be accesed withot creating an object, but they have to be iniatiliased.
    static void my_lense_type(){                     //static function can only access static data members.
        if(my_priscription < 0){
            cout << "concave lense is prescribed." << endl;
        }
        else if(my_priscription == 0){
            cout << "no lense is prescribed." << endl;
        }
        else{
            cout << "convex lense is prescribed." << endl;
        }
    }

    Lense(){
        cout << "simple constructor is called.\n";       //default/simple constructor
    }
    Lense(float R1, float R2, float refractive_index ){         //custom constructor(parematric)
        cout << "\nparematric constructor is called:\n";
        this->refractive_index =refractive_index;
        this->R1 = R1;
        this->R2 = R2;
    }
    Lense(Lense &temp){             
        cout << "custom copy constructor is called.\n";               //copy constructor(DEFAULT copy constructor is shallow type---> both origanl and copied obj point to same location in heap)
        this->R1 = temp.R1;
        this->R2 = temp.R2;
        this->refractive_index =temp.refractive_index;
    }
    ~Lense(){                                                       //Destructor
        cout << "custom destructor called.\n";
    }



    //Getter-Setter
    float getrefrective_index(){
        return refractive_index;
    }
    float getR1(){
        return R1;
    }
    float getR2(){
        return R2;
    }
    void setrefractive_index(float refractive_index){
        this-> refractive_index = refractive_index;        //this is a pointer that stores the addres of object.
    }
    void setR1(float R1){
        this-> R1 = R1;
    }
    void setR2(float R2){
        this->R2 = R2;
    }



    void print_focal_length(){            // function inside class
        cout << "focal length is: " << 1/((refractive_index - 1)*(1/R1- 1/R2))<< endl;
    }
};

float Lense::my_priscription = -2.5;  //initialising static data  memeber.

int main(){


    //Static Keword:
    cout << Lense::my_priscription << endl;
    Lense::my_lense_type();



/*   // Destrucotr:for statically called objects destructor:

    Lense lense5(14,14,1.5);
    Lense *lense = new Lense(12,-12,1.5);        // Dyanimic allocation of object in heap memory.
    lense->print_focal_length();
    delete lense;                 //Custom destructor is called when you delete the object.
*/


/*  //constructors:

    Lense lense3(10,-10,1.5);
    Lense lense4(lense3);              //copy all data of lense3 to lense4

    Lense lense2(20, -20, 1.5);        // parematric constructor
    lense2.refractive_index_left = 1;
    lense2.refractive_index_right = 1;
    lense2.print_focal_length();
    lense4.print_focal_length();
*/

/*  
    Lense lense1;
    lense1.setrefractive_index(1.5);   //getter-setter
    lense1.setR1(20);
    lense1.setR2(-20);

    float refractive_index_left;
    float refractive_index_right;
    
    cout << "\nrefractive index left: " << endl;
    cin >> refractive_index_left;
    cout << "refrative index right: " << endl;
    cin >> refractive_index_right;
    
    lense1.refractive_index_left = refractive_index_left;
    lense1.refractive_index_right = refractive_index_right;
    lense1.print_focal_length();

*/

    return 0;
}