#ifndef POINT_H
#define POINT_H

#include <iostream>

using namespace std;

class Point 
{
  friend ostream &operator<<( ostream &, const Point & ); 
  friend istream &operator>>( istream &, Point & ); 

private: 
  double x;
  double y;
};

#endif
