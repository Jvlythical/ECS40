#ifndef POINT_H
#define POINT_H

class Point 
{
public: 
  Point (double, double);
  void show () const;
  void set (double, double);
  bool isValid (const Point &) const; 
  
private: 
  double x;
  double y;
};

#endif
