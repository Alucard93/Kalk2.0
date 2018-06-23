#ifndef RGB_H
#define RGB_H

class RGB : public Color{
public:
  RGB:RGB(unsigned int r=0, unsigned int g=0, unsigned int b=0, Codec c=Codec::RGB) : Color(c, "colore RGB", 0, 255), red(r), greeen(g), blue(b){};
private:
  unsigned int red;
  unsigned int green;
  unsigned int blue;
};

#endif // RGB_H
