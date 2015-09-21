#include <iostream>
#include "point.h"

using namespace std; 

Point::Point (double xInit, double yInit)
  : x(xInit), y(yInit)
{  /* empty */  }

void Point::show () const
{
  cout << "Point @ (" << x << ", " << y << ")" << endl; 
}

void Point::set (double xVal, double yVal)
{
  x = xVal;  
  y = yVal;
}
