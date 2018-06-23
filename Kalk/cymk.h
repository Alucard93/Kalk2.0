#ifndef CYMK_H
#define CYMK_H

class CYMK : public Color{
public:
  CYMK::CYMK(unsigned int c=0, unsigned int m=0, unsigned int y=0, unsigned int k=0, Codec c=Codec::CYMK) : Color(c, "colore stampa", 0, 100), cyan(c), magenta(m), yellow(y), key_black(k){};
private:
  unsigned int cyan;
  unsigned int magenta;
  unsigned int yellow;
  unsigned int key_black;
};

#endif // CYMK_H
