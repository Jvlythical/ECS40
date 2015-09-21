// inheritance + constructor & destructor

#include <iostream>
#include "point.h"
#include "colorpoint.h" 

using namespace std; 

ColorPoint gcp(1.0, 1.0, GREEN); 
// Point
// ColorPoint

int main () 
{
  Point p(1.0, 1.0);
  // Point

  ColorPoint cp(2.0, 2.0, RED);
  // Point
  // ColorPoint

  for (int i = 0; i < 3; i++) {
    static ColorPoint scp(3.0, 3.0, BLUE); 
    //Point
    // ColorPoint
    Point p(4.0, 4.0); 
    // Point
  }

  return 0;  
}
