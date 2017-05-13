//============================================================================
// Name        : Coin.h
// Author      : nancy zhou
// Version     : 1.0
// Copyright   : no stealing
// Description :sideup returns true for a side and false for another
//============================================================================
#ifndef COIN_H
#define COIN_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>// to use time function

using namespace std;


class Coin
{
private:

    int sideUp;


public:

    Coin();
    int GetsideUp()const;//is constant b/c returns private member
    void Setsideup(int val);
    int toss(string val); //setSideUp mutator
    virtual ~Coin();

};


#endif // COIN_H
