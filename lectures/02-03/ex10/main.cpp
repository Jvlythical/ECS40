// An example to illustrate the concept of "class members and functions": 
// 1) static members & functions 
// 2) point out some common errors 

#include <iostream>
#include "point.h"

using namespace std; 

int main () 
{
  cout << "Total # of points: " << Point::getNum() << endl; 

  Point p(0.0,0.0); 

  cout << "Total # of points: " << Point::getNum() << endl; 

  {
    Point p1(1.0,1.0);
    Point p2(2.0,2.0);
    static Point p3(3.0,3.0);

    cout << "Total # of points: " << Point::getNum() << endl; 
  }

  cout << "Total # of points: " << Point::getNum() << endl; 

  // what is the size of Point now? 
  cout << "Size of the Point: " << sizeof(Point) << endl; 

  return 0;  
}
