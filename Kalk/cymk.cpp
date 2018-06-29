#include "cymk.h"

CYMK::CYMK(unsigned int c , unsigned int m, unsigned int y, unsigned int k) : CIExyz(0.430574 * ((1-k/100)*(1-c/100)) + 0.341550 * ((1-k/100)*(1-m/100)) + 0.178325 * ((1-k/100)*(1-c/100)),
                                                                                     0.222015 * ((1-k/100)*(1-c/100)) + 0.706655 * ((1-k/100)*(1-m/100)) + 0.071330 * ((1-k/100)*(1-c/100)),
                                                                                     0.020183 * ((1-k/100)*(1-c/100)) + 0.129553 * ((1-k/100)*(1-m/100)) + 0.939180 * ((1-k/100)*(1-c/100))){
  if(c>100 || m>100 || c>100 || y>100 || k>100)
    throw IllegalColourException("il colore non rienttra nei parametri");
  else{
    cyan=c;
    magenta=m;
    yellow=y;
    key_black=k;
  }
}
CYMK(CIExyz* from) : CIExyz(from->getx(), from->gety(),from->getz()){
    int tc;
    int tm;
    int ty;
    int tk;
}

CYMK(CYMK from){

}
void CYMK::getcymk(){
    cout<<cyan<<'\n'<<magenta<<'\n'<<yellow<<'\n'<<key_black<<'\n';
    this->getciexyz();
}
