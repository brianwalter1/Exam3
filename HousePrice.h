// File: HousePrice
// Created by Brian Walter on 12/7/2017.
// Copyright (c) 2017 WSU
//

#ifndef HW8_HOUSEPRICE_H
#define HW8_HOUSEPRICE_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/*!
 * Class HousePrice
 */
class HousePrice{
public:
    HousePrice();
    HousePrice(int id, int number, string street, string city, string state, int postalCode, double price);
    double getPrice() const;
    const string & getState() const;
    friend ostream & operator<<(ostream &os, const HousePrice &price);
private:
    int id;
    int number;
    string street;
    string city;
    string state;
    int postalCode;
    double price;
};


#endif //HW8_HOUSEPRICE_H
