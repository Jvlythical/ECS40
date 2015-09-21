#include <iostream>
#include "colorpoint.h"

using namespace std; 

ColorPoint::ColorPoint (double xInit, double yInit, Color cInit) 
  : Point(xInit, yInit), // what happens if we comment out this base constructor call?
    c(cInit)
{
  //  x = xInit;
  //  y = yInit; 
  //  c = cInit; 

  cout << "ColorPoint @: (" 
       << x << ", " << y << ", " << getColor() 
       << ")" << endl; 
} 

ColorPoint::~ColorPoint ()
{
  cout << "~ColorPoint @: (" 
       << x << ", " << y << ", " << getColor() 
       << ")" << endl; 
}

void ColorPoint::show () const
{
  cout << "ColorPoint @ (" 
       << x << ", " << y << ", " << getColor() 
       << ")" << endl; 
}

void ColorPoint::set (double xVal, double yVal, Color cVal)
{
  x = xVal;  y = yVal;  c = cVal;
}

string ColorPoint::getColor () const 
{
  switch (c) {
  case RED: return "RED"; 
  case GREEN: return "GREEN";
  case BLUE: return "BLUE";
  default: return "ERROR: BAD COLOR";
  }
}
