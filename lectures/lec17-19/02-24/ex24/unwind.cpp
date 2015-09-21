// demonstrate stack unwinding
#include <iostream>
#include <stdexcept>
using namespace std;

void f3() throw () // ( runtime_error )
{
   cout << "In f3" << endl;

   // no try block, stack unwinding occurs, return control to f2
   throw runtime_error( "runtime_error in f3" ); 
}

void f2() throw ( runtime_error )
{
   cout << "f3 is called inside f2" << endl;
   f3(); // stack unwinding occurs, return control to f1
} 

void f1() throw ( runtime_error )
{
   cout << "f2 is called inside f1" << endl;
   f2(); // stack unwinding occurs, return control to main
} 

int main()
{

  try 
    {
      cout << "f1 is called inside main" << endl;
      f1(); // call f1 which throws runtime_error
    } 
  catch ( runtime_error &error ) // handle runtime error
    {
      cout << "Exception occurred: " << error.what() << endl;
      cout << "Exception handled in main" << endl;
    }

  return 0;
} 

