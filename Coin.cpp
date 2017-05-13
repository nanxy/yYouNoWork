#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>// to use time function
#include "Coin.h"

Coin::Coin()
{
    srand (time(0));
}

int Coin::Getsideup()const
{
    return sideup;
}


void Coin::Setsideup(int val)
{
    sideup = val;

}
int Coin::toss(string val)

{
    int tossing;
    int side;
    tossing= rand() % 100+1;
    if(tossing%2==1)
    {
        side=0;
        return side;
    }
    else
    {
        side=1;
        return side;
    }

}


Coin::~Coin()
{
    //dtor
}
