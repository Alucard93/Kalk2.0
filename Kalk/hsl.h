#ifndef HSL_H
#define HSL_H

class HSL : public Color{
public:
  HSL::HSL(unsigned float h=0, unsigned float s=0, unsigned float l=0, unsigned int msl=360, Codec c=Codec::HSL) : Color(c, "boh", 0, 1), hue(h), saturation(s), lightness(l), max_sl(msl){};
private:
  unsigned float hue;
  unsigned float saturation;
  unsigned float lightness;
  unsigned int max_sl;
};

#endif // HSL_H
//
