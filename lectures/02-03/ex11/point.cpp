#include "point.h"

using namespace std; 

ostream &operator<<( ostream &os, const Point &p )
{
  os << "Point @ (" << p.x << ", " << p.y << ")";
  return os; 
}

istream &operator>>( istream &is, Point &p )
{
  is >> p.x >> p.y;
  return is; 
}
