#ifndef POINT_H
#define POINT_H

class Point 
{
public: 
  Point (double, double);
  void show () const;
  void set (double, double);
  
protected:    // notice the protected keyword; was private
  double x;
  double y;
};

#endif
