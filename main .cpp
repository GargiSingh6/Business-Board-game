#include <stdio.h>
#include <iostream>
#include"asset.h"
#include"player.h"
#include "board.h"
#include "cities.h"
#include "abstractasset.h"
#include "extras.h"
#include <sstream>
#include<string>
using namespace std;
void game()
{
    city *cities=createcities();
    abstract_asset *abstractassets=createabs();
    position *board = createboard(); 
    player arr[4];
    int p=0;
    while (p<4){
    arr[p].setvalues(p,-1,1000000,1);
    arr[p].id=p;
    p=p+1;
    }
    
    int i = 0;
    while (i < 4)
    {
        if (arr[i].kick==1)
        {
            
            if (i==3){
                i=0;
            
            }
            else{
        i = i + 1;
        }}
        else
        {
            cout<<"Turn Player: "<<i<<"\n";
            int dice = 1+rand()%12; 
            
            if (arr[i].pos()>0 ){
                board[arr[i].pos()].player="  ";
            }
            arr[i].incrementpos(dice);
            board[(arr[i].pos())].player=setplayer(i,board[(arr[i].pos())].player);
            //cout<<board[(arr[i].pos())].player<<"\n";
            printboard(board);
            if (board[(arr[i].pos())].type == 0)
            {
                cout<<"player "<<i << " has reached " << board[(arr[i].pos())].name << "\n";
                if (arr[i].assetstatus[arr[i].pos()] == 1)
                {
                    cout<<"would you like to build a house or a hotel here?";
                }
                if (arr[i].assetstatus[arr[i].pos()] == 0)
                {
                    if (cities[(arr[i].pos())].Status() == 0) //*city does not have owner
                    {
                        cities[(arr[i].pos())].printcard();
                        
                        int decision;
                        cin >> decision;
                        if (decision == 1)
                        {
                            arr[i].buy(&cities[(arr[i].pos())]);
                            cities[arr[i].pos()].owner=arr[i].id;
                            
                        }
                    }
                    else
                    {
                        cout << "you will have to pay rent of rs " << rent(cities[arr[i].pos()], arr[i]) << " \n";
                        arr[i].deduct(rent(cities[arr[i].pos()], arr[i])); //pay rent
                        cout<<cities[arr[i].pos()].owner;
                    }
                    
                }
            } //city
            else if (board[(arr[i].pos())].type == 1)
            {
                cout<<"player "<<i << " has reached " << board[(arr[i].pos())].name << "\n";
                if (arr[i].assetstatus[arr[i].pos()] == 1)
                {
                    cout << "you own this place \n";
                }
                else if (arr[i].assetstatus[arr[i].pos()] == 0)
                {
                    if (abstractassets[(arr[i].pos())].Status() == 0) //*asset does not have owner
                    {
                        cout << "would you like to buy " << board[arr[i].pos()].name << " for rs " << abstractassets[(arr[i].pos())].Price();
                       abstractassets[(arr[i].pos())].printcard();
                    
                        int decision;
                        cin >> decision;
                        if (decision == 1)
                        {
                            arr[i].buy(&abstractassets[(arr[i].pos())]);
                            abstractassets[arr[i].pos()].owner=arr[i].id;
                            cout<<arr[i].id;
                        }
                       
                    }
                    else
                    {
                    cout<<"you will have to pay rent of rs "<<rent(abstractassets[arr[i].pos()],arr[i])<<" \n";
                    arr[i].deduct(rent(abstractassets[arr[i].pos()],arr[i]));
                    arr[abstractassets[arr[i].pos()].owner].increment(rent(abstractassets[arr[i].pos()],arr[i]));//pay rent
                    cout<<abstractassets[arr[i].pos()].owner;
                    }
                }
            } //abstract asset
            else if (board[(arr[i].pos())].type == 2)
            {
                int turntemp, t;
                cout<<"player "<<i << " has reached " << board[(arr[i].pos())].name << "\n";
                cout << " you have to pay a fine of 300rs";
                
                {
                    arr[i].deduct(300); //pay rent
                    t = 0 ;
                    while (t < 4)
                    {
                        if (t != i)
                        {
                            arr[t].increment(300);
                        }
                        t=t+1;
                    }
                }
                
            } //jail
            else if (board[(arr[i].pos())].type == 3)
            {
                cout<<"player "<<i << " has reached " << board[(arr[i].pos())].name << "\n";
                cout << " \n  you will have to pay rs 100 to the bank\n";
                arr[i].deduct(100);

            } //clubhouse
            else if (board[(arr[i].pos())].type == 4)
            {
                cout<<"player "<<i << " has reached " << board[(arr[i].pos())].name << "\n";
                arr[i].deduct(community(dice));

            } //community
            else if (board[(arr[i].pos())].type == 5)
            {
                cout<<"player "<<i << " has reached " << board[(arr[i].pos())].name << "\n";
                arr[i].increment(chance(dice));
            } //chance
            else if (board[(arr[i].pos())].type == 6)
            {
                cout<<"player "<<i << " has reached " << board[(arr[i].pos())].name << "\n";
                cout << "you will have to pay 100rs for every asset you own.\n";
                cout<<"since you own "<< arr[i].Assetstotal() << " number of assets you will have to pay " << (arr[i].Assetstotal() * 100) << "rs\n";
                arr[i].deduct(arr[i].Assetstotal() * 100);
            } //incometax
            else if (board[(arr[i].pos())].type == 7)
            {
                cout<<"player "<<i << " has reached " << board[(arr[i].pos())].name << "\n";
                cout << "you will have to pay 100 rs for every house that you have built and 500rs for every hotel that you have built";
                cout << "\n your total comes to " << ((arr[i].Houses() * 100) + (arr[i].Hotels() * 500)) << "\n";
                arr[i].deduct(((arr[i].Houses() * 100) + (arr[i].Hotels() * 500)));
            } //wealth tax
        }
         
                                
        if (arr[i].Balance() < 0)
            {
                cout << "You are now bankrupt and out of the game\n" ;
                arr[i].kickout();
                board[arr[i].pos()].player="  ";
            }
        leaderboard(arr[0],arr[1],arr[2],arr[3]);
        int next;
        cin>>next;

            if (i==3){
                i=0;
            }
            else{
        i = i + 1;}
        
    }
}

int main()
{
    game();
}
