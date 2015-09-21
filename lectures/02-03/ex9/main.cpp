// An example to illustrate the use of the 'this' pointer

#include <iostream>
#include "point.h"

using namespace std; 

int main () 
{
  Point p(1.0,1.0);
  
  p.show();

  // isValid 
  
  Point p1(2.0,2.0);
  
  if (p.isValid(p1)) 
    cout << "Valid" << endl;
  else 
    cout << "Invalid" <<endl;

  if (p.isValid(p)) 
    cout << "Valid" << endl;
  else 
    cout << "Invalid" <<endl;

  return 0;  
}
