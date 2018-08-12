#ifndef YUV_H
#define YUV_H

class YUV : public Color{
public:
  YUV::YUV(unsigned float a=0.0, unsigned float b=0.0, unsigned float c=0.0, int luv=-1, int muv=1, Codec c=Codec::YUV) : Color(c, "cose", 0, 1), y(a), u(b), v(c), low_uv(luv), max_uv(muv){};
private:
  unsigned float y;
  unsigned float u;
  unsigned float v;
  int low_uv;
  int max_uv;
};

#endif // YUV_H
