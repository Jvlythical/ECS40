// A simple example to illustrate C++ overloading: << & >> stream operators 

#include "point.h"

using namespace std; 

int main () 
{
  Point p; 

  // read in the x & y of a Point object 
  cin >> p; 

  // output the Point object
  cout << p << endl;

  return 0;  
}

