// A simple example to illustrate the overloading of ++: 
// prefix and postfix (the use of the dummy int)

#include <iostream>
#include "point.h"

using namespace std; 

int main () 
{
  Point p, q, r;

  // int x = 0;
  // ++x = 10; 
  // cout << x << endl;

  q = p++; 
  q.show(); 
  p.show();

  r = ++p;
  r.show();

  ++p = Point(10.0,10.0); 
  p.show();

  p[1];

  return 0;  
}
