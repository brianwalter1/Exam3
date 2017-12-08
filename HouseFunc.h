// File: HouseFunc
// Created by Brian Walter on 12/7/2017.
// Copyright (c) 2017 WSU
//

#ifndef HW8_HOUSEFUNC_H
#define HW8_HOUSEFUNC_H

#include "HousePrice.h"

// Prototypes
void readCSV(const string fileIn,vector<HousePrice> &hp);
void houseMarketValues(vector<HousePrice> &hp);
void houseMarketPerState(vector<HousePrice> &hp);

#endif //HW8_HOUSEFUNC_H
