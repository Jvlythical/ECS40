#ifndef POINT_H
#define POINT_H

class Point 
{
public: 
  Point ();
  Point (double, double);
  void show ();
  void set (double, double);
  
  Point &operator++(); // prefix increment operator
  Point operator++( int ); // postfix increment operator
  Point& operator[](int);

private: 
  double x;
  double y;
};

#endif
