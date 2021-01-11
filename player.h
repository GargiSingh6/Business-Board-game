#include"asset.h"
#pragma once
class player
{
public:
    int id;
    int currentpos;
    int balance;
    int assetstotal;
    int kick;
    int houses_no;
    int hotels_no;
    int turn;
    
    int colourcount[4];
    int assetstatus[34];
    void setvalues(int id, int pos,int bal,int turn_){
        id=id;
        currentpos=pos;
        balance=bal;
        turn=turn_;
        int t=0;
        while (t<34){
            assetstatus[t]=0;
            t=t+1;
        }
    }
    int Balance()
    {
        return balance;
    }
    void increment(int amount)
    {
        balance = balance + amount;
    }
    void deduct(int amount)
    {
        balance = balance - amount;
    }
    void buy(abstract_asset *k)
    {
        k->setowner(id);
        k->setstatus();
        assetstatus[k->Id()] = 1;
        //assetstotal = assetstotal + 1;
        balance = balance - (k->Price());
    }
    void buy(city *k)
    {
        k->setowner(id);
        //colourcount[k->Colour()] = colourcount[k->Colour()] + 1;
        k->setstatus();
        //assetstotal = assetstotal + 1;
        balance = balance - (k->Price());
        assetstatus[k->Id()] = 1;
        //k->print();
    }
    void incrementpos(int i)
    {
        currentpos=currentpos+i;
        if (currentpos>34){
            currentpos=currentpos-35;
        }
    }
    int pos()
    {
        return currentpos;
    }
    int Assetstotal()
    {
        int i = 0;
        int sum = 0;
        while (i < 35)
        {
            if (assetstatus[i] == 1)
            {
                sum = sum + 1;
            }
            i = i + 1;
        }
        return sum;
    }
    void buildhouse(city *k)
    {
        deduct(k->buildhouse());
        houses_no = houses_no + 1;
    }
    void buildhotel(city *k)
    {
        deduct(k->buildhotel());
        hotels_no = hotels_no + 1;
    }
    int Houses()
    {
        return houses_no;
    }
    int Hotels()
    {
        return hotels_no;
    }
    void kickout()
    {
        kick = 1;
    }
    
};