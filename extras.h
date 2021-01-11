
#include <stdio.h>
#include <iostream>
using namespace std;
#include"asset.h"
#include "player.h"
#pragma once

int rent(city city, player player)
{
    return city.baserent;
}
int rent(abstract_asset asset, player player)
{
    return asset.baserent;
}
int community(int dice)
{
    if (dice % 2 == 0)
    {
        return 1000;
    }
    else
    {
        return 500;
    }
}
int chance(int dice)
{
    if (dice % 2 == 0)
    {
        return 1000;
    }
    else
    {
        return 500;
    }
}
void leaderboard(player a, player b, player c, player d){
    cout<<"\n"<<"PLAYER ID"<<"           BALANCE\n";
    if (a.kick!=1){
    cout<<"     0"<<"            "<<a.balance<<"\n";
    }
    if (b.kick!=1){
    cout<<"     1"<<"            "<<b.balance<<"\n";}
    if (c.kick!=1){
    cout<<"     2"<<"            "<<c.balance<<"\n";}
    if (d.kick!=1){
    cout<<"     3"<<"            "<<d.balance<<"\n";}
    cout<<"\n";
}
string setplayer(int i,string player){
    if (player =="  "){
    if (i==0){
        return "P0";
    }
    else if (i==1){
        return "P1";
    }
    else if (i==2){
        return "P2";
    }
    else if(i==3)
    {
        return "P3";
    }}
    else {
        if (i==0){
        return player+"P0";
    }
    else if (i==1){
        return player+"P1";
    }
    else if (i==2){
        return player+"P2";
    }
    else if(i==3)
    {
        return player+"P3";
    }
    }
}

