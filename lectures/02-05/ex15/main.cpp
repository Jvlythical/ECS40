// A simple example to illustrate C++ inheritance

#include <iostream>
#include "point.h"
#include "colorpoint.h" 

using namespace std; 

int main () 
{
  Point *p = new Point(1.0, 1.0);
  p->show(); 

  ColorPoint *cp = new ColorPoint(2.0, 2.0, RED);
  cp->show();

  // p = cp;
  // p->show();    // Q1: will this output the color? 

  // cp = p;       // Q2: what happens if we uncomment the code? 
  // cp->show();
  
  // Q3: what is the size of a ColorPoint object? 
  cout << "Size of a Point object: " << sizeof(Point) << endl;
  cout << "Size of a ColorPoint object: " << sizeof(ColorPoint) << endl;

  return 0;  
}
