#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
//? note in maps the time taken to insert is log(n), but it become string.siz() * log(n) for a string as we need to pay attention on the lexographic comparision for sorting. But in unorderd_map mostly insertion and extraction time is O(1)
//? in unordered maps we can't have complex data types like pair, vector, etc, as they don't have an inbuilt hash.
// we can also put a valude in map just like pair---> map<int,int> m = {{0,1},{1,2}......}
using namespace std;

class CountryRecord{

    // storing data by data members
    public:
    string name;
    int population;
    float latitude, longitude;

    CountryRecord(){

    }

    CountryRecord(string name, int population, float latitude, float longitude) {
        this->name = name;
        this->population = population;
        this->latitude = latitude, this->longitude = longitude;
    }
};

int main(){

       // using maps to find req country(UK)
    map <string, CountryRecord> countries;                                  //Create a map
    countries["India"] = CountryRecord{"India", 100000000, 24.32, 7.90};    //Assign a vale to key--->Method-1
    countries["Russia"] = CountryRecord{"Russia", 189222, 24.30, 155.89};
    countries["UK"] = CountryRecord{"UK", 500085, 17.34, 89.56};
    countries["Bhutan"] = CountryRecord("Bhutan", 45673, 24.32, 7.99);
    CountryRecord Mexico;                                                   //Assign a vale to key--->Method-2
    Mexico.name = "Mexico";
    Mexico.population = 64734;
    Mexico.latitude = 23.89;
    Mexico.longitude = 38.12;
    countries["Mexico"] = Mexico;


    CountryRecord& req_country = countries["UK"];   //Faster              //no need to iterate through container elements and directly get the req_element and its data; there was no need to create a pointer.
    cout << "UK population is: " << req_country.population << endl;

    //.at--->if we had a const map then [] won't work for indexing because it is designed to mutate
    CountryRecord req_country2 = countries.at("India");
    cout << "India population is: " << req_country2.population << endl;

    //.find
    if(countries.find("Mexico") != countries.end()){         // map.find(key) returns an iterator pointing to the element with the given key — or to the end() of the map if the key is not found.
        cout << "Mexico exist in our list!!\n";              // .end() also returns an iterator pointiong 1 unit ahead of end of map.
        cout << "It's population is: " << (countries.at("Mexico")).population;
    }

    // .erase()
    countries.erase("Bhutan");
    // we can also erase using iterator
    auto it = countries.find("UK");
    countries.erase(it);

    //iterating through map(SLOW)
    // // Method-1(prefer)
    for(auto &[key, value] : countries){
        cout << "name of country is: " << key << " population is: " << value.population;
    }

    // Method-2
    for(auto &kv: countries){
        string name = kv.first;
        CountryRecord record = kv.second;
        cout << "name of country is: " << name << endl;
        cout << "population is: " << record.population << endl; 
    }



    

    /*  //NOTE---->indexing operator([]) always insert things in map even in following:-
    CountryRecord& req_country = countries["UK"];
    req_country.name = "UK";
    req_country.population = 2876324;
    // i.e. if UK didn't existed inside countries map then it will automatically insert it and this is better way to insert then method two as we are creating an obj dirtctly inside map and not first creating an obj and then copying it.
    */

    /* //    using vector and then iterting through it to find desired country(UK)
    
    vector <CountryRecord> countries;
    countries.push_back({"India", 100000000, 24.32, 7.90});  // Aggregate initialisation
    countries.push_back({"Russia", 189222, 24.30, 155.89});  
    countries.push_back({"UK", 500085, 17.34, 89.56});
    CountryRecord Mexico;
    countries.emplace_back(Mexico);                         // Emplace_Back
    Mexico.population = 2345667;
    countries.emplace_back("Bhutan", 45673, 24.32, 7.99);



    // TWO DIFF.  PRINTING METHODS
    for(int i = 0; i < countries.size(); i++){
        if(countries[i].name == "UK"){
            cout << countries[i].name << endl;
            cout << "population: " << countries[i].population << endl;
            cout << "cordinates: " << countries[i].latitude << " , " << countries[i].longitude << endl;
        }
    }
    for(CountryRecord c:countries){
        if(c.name == "UK"){
            cout << c.name << endl;
            cout << "population: " << c.population << endl;
            cout << "cordinates: " << c.latitude << " , " << c.longitude << endl;
        }
    }
    */
    return 0;
}