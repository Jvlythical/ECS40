#ifndef COLORPOINT_H
#define COLORPOINT_H

#include <string>
#include "point.h" 

using namespace std;

enum Color { RED, GREEN, BLUE }; 

class ColorPoint : public Point  
{
public: 
  ColorPoint (double, double, Color);
  ~ColorPoint (); 
  void show () const;
  void set (double, double, Color);
  
private: 
  Color c; 
  string getColor () const; 
};

#endif
