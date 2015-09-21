#include <iostream>
#include "point.h"

using namespace std; 

int Point::c = 0;  // Note: no static before int. Q: Why?  
                   // Q: How do you initialized a const non-static data member?  

Point::Point (double xInit, double yInit)
{ 
  x = xInit; 
  y = yInit; 
  
  c++;
} 

Point::~Point () 
{
  c--;
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
  c = 0;
  return (this != &np);     
}

int Point::getNum ()  // no static here either. Again, why? 
{
  // think: what can you access in a static member function? 
  // in particular, can you access x or y? 

  return c;
}

