#ifndef COLOUR_H
#define COLOUR_H

class Color{
public:
  Color:Color(Codec c=Codec::NONE, string s=0, int ll=0, int ul=0) : rap(c), desc(s), low_limit(ll), up_limit(ul){};
  virtual void show_rap()=0;
  virtual void show_desc()=0;
  virtual Color* convert(Color* from, Codec to)=0;
  virtual Color* negate(Color* base)=0;
  virtual Color* mix(Color* c1, Color* c2)=0;

private:
  Codec rap;
  string desc;
  int low_limit;
  int up_limit;
};

#endif // COLOUR_H
