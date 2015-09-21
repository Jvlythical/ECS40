#include <iostream>
#include "point.h"

using namespace std; 

Point::Point () 
{
  x = y = 0.0; 
}

Point::Point (double xInit, double yInit)
{ 
  x = xInit; 
  y = yInit; 
} 

void Point::show ()
{
  cout << "Point @ (" << x << ", " << y << ")" << endl; 
}

void Point::set (double xVal, double yVal)
{
  x = xVal;
  y = yVal;
}

Point &Point::operator++()
{
  x++;
  y++;
  
  return *this;
}

Point Point::operator++( int )
{
  Point t = *this;
  
  x++;
  y++;

  return t;
}

Point& Point::operator[](int) {
	cout << "hi" << endl;

	return *this;
}
