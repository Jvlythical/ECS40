#ifndef POINT_H
#define POINT_H

class Point 
{
public: 
  Point (double, double);
  ~Point (); 
  void show () const;
  void set (double, double);
  bool isValid (const Point &) const; 
  
  static int getNum ();  

private: 
  double x;
  double y;
  
  static int c;   // shared among all objects for the class Point
                  // so it exists even if no Point object is created  
};

#endif
