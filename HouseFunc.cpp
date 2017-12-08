// File: HouseFunc
// Created by Brian Walter on 12/7/2017.
// Copyright (c) 2017 WSU
//

#include <iostream>
#include <fstream>      //Included to open csv file
#include <stdlib.h>     //Included to convert strings from file input into double
#include <vector>
#include <map>
#include "HouseFunc.h"
#include "HousePrice.h"
//I could not get csv.h to work, so I just wrote my funtion to parse the csv file on its own
#include <algorithm>

using namespace std;

struct lessThan{
    inline bool operator() (const HousePrice& lhs, const HousePrice& rhs){
        return(lhs.getPrice() < rhs.getPrice());
    }
};

/*!
 * Read CSV Mock Data. Parses each record in the file to
 * an object of HousePrice house. Then, populate a vector
 * of HousePrice objects with all the records.
 * @param fileIn File name <string>
 * @param hp Reference to Vector of HousePrice Objects
 */
void readCSV(const string fileIn,vector<HousePrice>& hp)
{
    ifstream file(fileIn);
    
    cout << endl;   //Formatting Purposes
    
    if(!file.is_open()){ 
        cout<< "Error opening file\n\n";
    }else{
        string street, city, state, id, number, postalCode, price;
        while(getline(file, id, ',')){  //Only run as long as there is a new line starting with an id followed by a comma
            int i = atoi(id.c_str());
            getline(file, number, ',');
            int n = atoi(number.c_str());
            getline(file, street, ',');
            string s = street;
            getline(file, city, ',');
            string c = city;
            getline(file, state, ',');
            string st = state;
            getline(file, postalCode, ',');
            int pc = atoi(postalCode.c_str());
            getline(file, price, '\n');
            double p = atof(price.c_str());
            
            if(i)   //Check to make sure it is a valid entry before adding
                hp.push_back(HousePrice(i, n, s, c, st, pc, p));
        }
    
        for(unsigned int i = 0; i<hp.size(); i++){
            cout << hp[i] << endl;
        }
        cout << endl;
    }
}


/*!
 * Sort the Vector of HousePrice Objects by price. Display the most affordable
 * and the most expensive house from the vector.
 * @param hp Reference to vector<HousePrice>
 */
void houseMarketValues(vector<HousePrice> &hp)
{
    // Sort by 
    sort(hp.begin(), hp.end(), lessThan());
    cout << "Most Affordable Home: " << hp[0] << endl;
    cout << "Most Expensive Home: " << hp[999] << endl << endl;
}


/*!
 * Sort the Vector of HousePrice Objects by state. Display the
 * number of houses per state.
 * It uses a map to count instances per state.
 * @param hp Reference to vector<HousePrice>
 */
void houseMarketPerState(vector<HousePrice> &hp)
{
    // Sort by State
    map<string,int> states;
    int counter = 0;
    for(unsigned int i = 0; i<hp.size(); i++){
        if(states.count(hp[i].getState())){
            states[hp[i].getState()] += 1;
        }else{
            states[hp[i].getState()] = 1;
        }
    }
    for(auto i = states.begin(); i != states.end(); i++){
        cout << i->first << " " << i->second;
        counter++;
        if(counter%10 == 0){
            cout << "\n";
        }else{
            cout << "    ";
        }
    }
}
