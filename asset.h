
#include <stdio.h>
#include <iostream>
using namespace std;
#pragma once

class asset
{
public:
    int id; //same as position no. on board
    string name;
    int baserent;
    int owner;
    int bank_value;
    int status;
    int price;
    void printcard(){
        cout<<"\nname: "<<name<<"\n";
          cout<<"rent: "<<baserent<<"\n";
      cout<<"price: "<<price<<"\n";    
      cout<<"press 1 to buy";
    }

};
class city : public asset
{
public:

    int colour;
    
    int houses_no;
    int hotels_no;
    int score;
    
    int Owner()
    {
        return owner;
    }
    void setowner(int k)
    {
        owner = k;
    }
    void setstatus()
    {
        //cout<<"AAAA";
        status = 1;
    }
    int Status()
    {
        return status;
    }
    int Price()
    {
        return price;
    }
    void print()
    {
        cout << status << " " << owner;
    }
    int Id()
    {
        return id;
    }
    int Colour()
    {
        return colour;
    }
    void setrent()
    {
        cin >> baserent;
    }
    int Score()
    {
        if (hotels_no == 0)
        {
            return houses_no * 2;
        }
        else
        {
            return 8;
        }
    }
    int Hotel()
    {
        return hotels_no;
    }
    int Houses()
    {
        return houses_no;
    }
    int buildhouse()
    {
        houses_no = houses_no + 1;
        baserent = baserent * 2;
        return price / 5;
    }
    int buildhotel()
    {
        hotels_no = hotels_no + 1;
        baserent = baserent * 2;
        return price / 2;
    }
    void setvalues(int idlol, string namelol , int pricelol,int baserentlol){
	    id=idlol;
	    name=namelol;
	    price=pricelol;
	    baserent=baserentlol;
	}
};
class abstract_asset : public asset
{
    string partner;
public:
    
    string Partner();
    
    int Owner()
    {
        return owner;
    }
    void setowner(int k)
    {
        owner = k;
    }
    void setstatus()
    {
        //cout<<"AAAA";
        status = 1;
    }
    int Status()
    {
        return status;
    }
    int Price()
    {
        return price;
    }
    void print()
    {
        cout << status << " " << owner;
    }
    int Id()
    {
        return id;
    }
    void setvalues(int idlol, string namelol , int pricelol,int baserentlol){
	    id=idlol;
	    name=namelol;
	    price=pricelol;
	    baserent=baserentlol;
	}
	
};