#ifndef POINT_H
#define POINT_H

class Point 
{
public: 
  Point (double, double);
  virtual void show () const;  // note 1: "virtual" keyword 
  void set (double, double);

  virtual Point * bar() {
    std::cout << "Point"; 
    return this; 
  }
  
protected: // note 2: "protected" keyword 
  double x;
  double y;
};

#endif
