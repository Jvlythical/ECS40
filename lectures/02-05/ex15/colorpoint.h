#ifndef COLORPOINT_H
#define COLORPOINT_H

#include <string>
#include "point.h" 

using namespace std;

enum Color { RED, GREEN, BLUE }; 

class ColorPoint : public Point  // notice public keyword -> public inheritance
{
public: 
  ColorPoint (double, double, Color);
  void show () const;
  void set (double, double, Color);
  string getColor () const; 
  
private: 
  Color c; 
};

#endif
