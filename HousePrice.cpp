// File: HousePrice
// Created by Brian Walter on 12/7/2017.
// Copyright (c) 2017 WSU
//

#include "HousePrice.h"

HousePrice::HousePrice(){}  //Empty Constructor

HousePrice::HousePrice(int i, int num, string s, string c, string st, int pc, double p){
    id = i;
    number = num;
    street = s;
    city = c;
    state = st;
    postalCode = pc;
    price = p;
}

double HousePrice::getPrice() const{
    return price;
}

const string & HousePrice::getState() const{
    return state;
}

ostream & operator<<(ostream &os, const HousePrice &price){
    cout << "id: " << price.id << " number: " << price.number << " street: " << price.street << " city: " << price.city << " state: " 
         << price.state << " postalCode: " << price.postalCode << " price: " << setprecision(15) << price.price;
}