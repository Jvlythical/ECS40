// A simple exception-handling example that checks for
// divide-by-zero exceptions

#include <iostream>
#include <stdexcept>
using namespace std;

// DivideByZeroException objects should be thrown by functions
// upon detecting division-by-zero exceptions
class DivideByZeroException : public runtime_error 
{
public:
   // constructor specifies default error message
   DivideByZeroException()
      : runtime_error( "attempted to divide by zero" ) {}
}; 

// perform division and throw DivideByZeroException object if 
// divide-by-zero exception occurs
double quotient( int numerator, int denominator )
{
   // throw DivideByZeroException if trying to divide by zero
   if ( denominator == 0 )
      throw DivideByZeroException(); // terminate function

   // return division result
   return static_cast< double >( numerator ) / denominator;
} // end function quotient

int main()
{
   int number1; // user-specified numerator
   int number2; // user-specified denominator
   double result; // result of division

   cout << "Enter two integers (end-of-file to end): ";

   while ( cin >> number1 >> number2 ) 
   {
      // try block contains code that might throw exception
      // and code that should not execute if an exception occurs
      try 
      {
         result = quotient( number1, number2 );
	 				
	 				try {
	   				cout << "The quotient is: " << result << endl;
	   				throw 10.1;
	 				}
	 				catch (double) {
	   				cout << "I'm here" << endl; 
	 				}
      } 
      catch (int) {
				cout << "I'm outside" << endl; 
      } 
    	catch (DivideByZeroException &divideByZeroException ) // why the &?  
      {
					cout << "Exception occurred: "
	     		<< divideByZeroException.what() << endl;   // what is a virtual 
	                                                // member function
      } 
      catch (...) { cout << "We are here" << endl; } 

      cout << "\nEnter two integers (end-of-file to end): ";
   } 

   cout << endl;
} 
