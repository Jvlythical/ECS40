#include <iostream>
#include "point.h"

using namespace std; 

Point::Point (double xInit, double yInit)
{ 
  x = xInit; 
  y = yInit; 
} 

void Point::show () const
{
  cout << "Point @ (" << x << ", " << y << ")" << endl; 

  cout << "Point @ (" << this->x << ", " << this->y << ")" << endl; 

  cout << "Point @ (" << (*this).x << ", " << (*this).y << ")" << endl; 
  
}

void Point::set (double xVal, double yVal)
{
  x = xVal;
  y = yVal;
}

bool Point::isValid (const Point &np) const
{
  return (this != &np);     
}
