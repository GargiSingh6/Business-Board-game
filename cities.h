#include"asset.h"

city* createcities(){
     city *cities = new city[100];
     cities[0].setvalues(0, "Mumbai", 10500, 1100);
    cities[3].setvalues(3, "ahemadabad", 4000, 1100);
    cities[5].setvalues(5, "indore", 2500, 1100);
    cities[7].setvalues(7, "jaipur", 5000, 1100);
    cities[9].setvalues(9, "newdelhi", 6000, 1100);
    cities[10].setvalues(10, "chandigarh", 3500, 1100);
    cities[13].setvalues(13, "shimla", 2500, 1100);
    cities[14].setvalues(14, "amritsar", 3300, 1100);
    cities[16].setvalues(16, "srinagar", 5500, 1100);
    cities[18].setvalues(18, "agra", 4000, 1100);
    cities[20].setvalues(20, "nagpur", 2500, 1100);
    cities[21].setvalues(21, "patna", 2500, 1100);
    cities[22].setvalues(22, "darjeeling", 3000, 1100);
    cities[24].setvalues(24, "calcutta", 4000, 1100);
    cities[25].setvalues(25, "hyderabad", 6000, 1100);
    cities[27].setvalues(27, "chennai", 5000, 1100);
    cities[29].setvalues(29, "bengaluru", 8000, 1100);
    cities[31].setvalues(31, "mysore", 4000, 1100);
    cities[32].setvalues(32, "cochin", 2500, 1100);
    cities[34].setvalues(34, "goa", 3300, 1100);
    return cities;
     
}