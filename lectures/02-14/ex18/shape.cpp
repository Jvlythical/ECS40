//
// to illustrate the concept of abstract classes & pure virtual functions 
//

#include <iostream>
#include "point.h"         

using namespace std;

class Shape {
public:
  Shape(const Point & o) : origin (o) { /* empty body */ }
  virtual ~Shape()   { /* empty body */ } 

  virtual void draw() = 0;  // pure virtual function; notice the "= 0" 

protected:
  Point origin;
};
        
class Line : public Shape 
{
public:
  Line(const Point &o, const Point &d) : Shape(o), dest(d) { } 
  ~Line() {cout << "~Line" << endl; } 

  void draw() 
  {
    cout << "Line: \t"; 
    origin.show();
    cout << "\t";
    dest.show();
  }

private: 
  Point dest; 
};
        
class Circle : public Shape {
public:
  Circle(const Point &o, double r) : Shape (o), radius (r) { } 
  ~Circle() {cout << "~Circle" << endl; } 

  void draw() 
  {
    cout << "Circle: ";
    origin.show();
    cout << "\tRadious: " << radius << endl; 
  }

private: 
  double radius; // radius 
};
        
int main()
{

  Shape *s[3];

  s[0] = new Line(Point(0.0, 0.0), Point(1.0,1.0));
  s[1] = new Circle(Point(0.0, 0.0), 3.0);
  s[2] = new Line(Point(0.0, 0.0), Point(-1.0, -1.0));

  for (int i = 0; i < 3; i++)
    s[i]->draw();

  for (int i = 0; i < 3; i++)
    delete s[i];        

  return 0;
}
