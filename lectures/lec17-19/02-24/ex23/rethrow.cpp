// Demonstrating exception rethrowing.
#include <iostream>
#include <exception>
using namespace std;

void throwException() 
{
   try 
   {
      cout << "  Function throwException throws an exception\n";
      throw exception();
   }
   catch ( exception & )
   {
      cout << "  Exception handled in function throwException"
         << "\n  Function throwException rethrows exception";

      throw; // rethrow exception for further processing
   } 

   
   cout << "Q1: should this print?\n";
}

int main()
{

   try 
   {
      cout << "\nmain invokes function throwException\n";
      throwException();
      cout << "Q2: should this print?\n";
   }
   catch ( exception & ) 
   {
      cout << "\n\nException handled in main\n";
   } 

   cout << "Program control continues after catch in main\n";
}

