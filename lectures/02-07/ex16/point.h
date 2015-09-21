#ifndef POINT_H
#define POINT_H

class Point 
{
public: 
  Point (double, double);
  ~Point (); 
  void show () const;
  void set (double, double);
  
protected: 
  double x;
  double y;
};

#endif
