#ifndef YCBCR_H
#define YCBCR_H

class YCbCr : public YUV{
public:
YCbCr:YCbCr() : YUV() {};
private:
  unsigned float cb;
  unsigned float cr;
};

#endif // YCBCR_H
