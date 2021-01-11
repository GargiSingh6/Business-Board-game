#include <stdio.h>
#include <iostream>
using namespace std;


struct position
{
    string player;
    string name;
    int type; //0 for city 1 for abstract 2 for jail 3 for club 4 for community 5 for chance 6 for income 7 for wealth
};

position *createboard()
{
    position *arr = new position[100];
    //perform operations on arr[0],arr[1] and so on
    int lol=0;
    while (lol<35){
        arr[lol].player="  ";
        lol=lol+1;
    }
    arr[0].name = "Mumbai";
    arr[0].type = 0;
    arr[1].name = "Water Works";
    arr[1].type = 1;
    arr[2].name = "Railway";
    arr[2].type = 1;
    arr[3].name = "Ahemadabad";
    arr[3].type = 0;
    arr[4].name = "Income Tax";
    arr[4].type = 6;
    arr[5].name = "Indore";
    arr[5].type = 0;
    arr[6].name = "Chance";
    arr[6].type = 5;
    arr[7].name = "Jaipur";
    arr[7].type = 0;
    arr[8].name = "Jail";
    arr[8].type = 2;
    arr[9].name = "New Delhi";
    arr[9].type = 0;
    arr[10].name = "Chandigarh";
    arr[10].type = 0;
    arr[11].name = "electric company";
    arr[11].type = 1;
    arr[12].name = "Best";
    arr[12].type = 1;
    arr[13].name = "Shimla";
    arr[13].type = 0;
    arr[14].name = "Amritsar";
    arr[14].type = 0;
    arr[15].name = "Community Chest";
    arr[15].type = 4;
    arr[16].name = "Srinagar";
    arr[16].type = 0;
    arr[17].name = "ClubHouse";
    arr[17].type = 3;
    arr[18].name = "Agra";
    arr[18].type = 0;
    arr[19].name = "Chance";
    arr[19].type = 5;
    arr[20].name = "Nagpur";
    arr[20].type = 0;
    arr[21].name = "Patna";
    arr[21].type = 0;
    arr[22].name = "Darjeeling";
    arr[22].type = 0;
    arr[23].name = "Air India";
    arr[23].type = 1;
    arr[24].name = "Calcutta";
    arr[24].type = 0;
    arr[25].name = "Hyderabad";
    arr[25].type = 0;
    arr[26].name = "ClubHouse";
    arr[26].type = 3;
    arr[27].name = "Chennai";
    arr[27].type = 0;
    arr[28].name = "Community Chest";
    arr[28].type = 4;
    arr[29].name = "Bengaluru";
    arr[29].type = 0;
    arr[30].name = "Wealth Tax";
    arr[30].type = 7;
    arr[31].name = "Mysore";
    arr[31].type = 0;
    arr[32].name = "Cochin";
    arr[32].type = 0;
    arr[33].name = "Motorboat";
    arr[33].type = 1;
    arr[34].name = "Goa";
    arr[34].type = 0;
    return arr;
}

void printboard(position board[]){
    int i=8;
    int t=9;
    int m=0;
    while(m<72){
        cout<<"-";
        m=m+1;
    }
    cout<<"\n -->>   |";
    while (t<18){
        cout<<"| "<<(board[t].name).substr(0, 3)<<" ";
        t++;
    }
    cout<<"|\n";
    t=9;
    cout<<" -->>   |";
    while (t<18){
        cout<<"| "<<(board[t].player)<<" |";
        t++;
    }
    
    cout<<"|\n";
    int p=18;
    while(i>=0 && p<=26){
        cout<<" |"<<(board[i].name).substr(0, 3)<<"|"<<(board[i].player)<<"|\t\t\t\t\t\t\t"<<"|"<<(board[p].player)<<"|"<<(board[p].name).substr(0, 3)<<"|\n";
        i--;
        p++;
    }
    cout<<"     ";
    int q=34;
    while (q>=26){
        cout<<" "<<(board[q].player)<<"   |";
        q--;
    }
    cout<<"\n START ^^";
    q=34;
    cout<<" |";
    while (q>26){
        cout<<"| "<<(board[q].name).substr(0, 3)<<" |";
        q--;
    }
    m=0;
     cout<<"\n";
    while(m<72){
        cout<<"-";
        m=m+1;
    }
    cout<<"\n";
    
    
}