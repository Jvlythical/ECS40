// Main goals of this example: 
// 1) illustrate dynamic (or late) binding (aka dynamic dispatch) 
// 2) understand the difference between dynamic vs. static cast
//

#include <iostream>
#include "point.h"
#include "colorpoint.h" 

using namespace std; 

int main () 
{
  Point *p = new Point(1.0, 1.0);
  p->show(); 

  // const char *s = "Hello"; 
  
  // cout << s << static_cast<const void *>(s) << endl;

  ColorPoint *cp1 = new ColorPoint(2.0, 2.0, RED);
  cp1->show();

  p = cp1;  // Q: How about cp1 = p? 
  p->show();

  Point *cp3 = new ColorPoint (2, 2, RED);
  cp3->show();
  
  // ColorPoint *cp2 = dynamic_cast<ColorPoint *> (p);  // Q: what is cp2? 
  // ColorPoint *cp2 = static_cast <ColorPoint *> (p);
  // ColorPoint *cp2 = static_cast <ColorPoint *> (100);
  // ColorPoint *cp2 = (ColorPoint *) (100);
  // cp2->show();
  //cp2->foo();

  cout << "Size of a Point object: " << sizeof(Point) << endl;
  cout << "Size of a ColorPoint object: " << sizeof(ColorPoint) << endl;
  
  return 0;  
}
