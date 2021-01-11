#include"asset.h"
abstract_asset* createabs(){
     abstract_asset *abstractassets = new abstract_asset[100];
     abstractassets[1].setvalues(1, "waterworks", 6000, 1100);
    abstractassets[2].setvalues(2, "railway", 9000, 800);
    abstractassets[11].setvalues(11, "electric company", 6000, 1100);
    abstractassets[23].setvalues(23, "airindia", 11000, 1100);
    abstractassets[33].setvalues(33, "motorboat", 6000, 600);
    abstractassets[12].setvalues(12, "best", 5000, 400);
    return abstractassets;
     
}