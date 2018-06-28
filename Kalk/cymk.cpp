#include "cymk.h"

CYMK::CYMK(unsigned int c=0, unsigned int m=0, unsigned int y=0, unsigned int k=0){
  if(c>100 || m>100 || c>100 || y>100 || k>100)
    throw IllegalColourException("il colore non rienttra nei parametri");
  else{
    double x = 0.430574 * ((100-k)*(100-c)*2.55) + 0.341550 * ((100-k)*(100-m)*2.55) + 0.178325 * ((100-k)*(100-y)*2.55);
    double y = 0.222015 * ((100-k)*(100-c)*2.55) + 0.706655 * ((100-k)*(100-m)*2.55) + 0.071330 * ((100-k)*(100-y)*2.55);
    double z = 0.020183 * ((100-k)*(100-c)*2.55) + 0.129553 * ((100-k)*(100-m)*2.55) + 0.939180 * ((100-k)*(100-y)*2.55);
    CIExyz(x, y, z);
    cyan=c;
    magenta=m;
    yellow=y;
    key_black=k;
  }
}
