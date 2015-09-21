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
  virtual void show () const;
  void set (double, double, Color);

  // note 3: add a new function which doesn't do anything 
  virtual void foo () { cout << c << endl; /* empty */ }; 

  virtual ColorPoint *bar() { 
    std::cout << "ColorPoint"; 
    return this; 
  }
  
private: 
  Color c;    // note 4: a new data member 
  string getColor () const; // note 5: a new private member function
};

#endif
