// 1) demonstrate the use of function objects
// 2) discuss its two benefits over ordinary functions: 
// a) performance; b) state 

#include <iostream>
#include <vector>       // vector class-template definition
#include <algorithm>    // copy algorithm
#include <numeric>      // accumulate algorithm
#include <functional>   // binary_function definition
#include <iterator>     // ostream_iterator
using namespace std;

// binary function adds square of its second argument and the
// running total in its first argument, then returns the sum 
int sumSquares( int total, int value ) 
{ 
   return total + value * value; 
}

// binary function class template defines overloaded operator()
// that adds the square of its second argument and running     
// total in its first argument, then returns sum               
template< typename T > 
class SumSquaresClass : public binary_function< T, T, T > 
{
public:
   // add square of value to total and return result
   T operator()( const T &total, const T &value )
   { 
      return total + value * value; 
   } 
private: 
  int count; 
}; 

int main()
{
   const int SIZE = 10;
   int array[ SIZE ] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
   vector< int > integers( array, array + SIZE ); // copy of array
   ostream_iterator< int > output( cout, " " );
   int result;

   cout << "vector integers contains:\n";
   copy( integers.begin(), integers.end(), output );

   // calculate sum of squares of elements of vector integers
   // using binary function sumSquares
   result = accumulate( integers.begin(), integers.end(), 
      0, sumSquares );

   cout << "\n\nSum of squares of elements in integers using "
      << "binary\nfunction sumSquares: " << result;

   // calculate sum of squares of elements of vector integers
   // using binary function object 
   result = accumulate( integers.begin(), integers.end(), 
      0, SumSquaresClass< int >() );

   cout << "\n\nSum of squares of elements in integers using "
      << "binary\nfunction object of type " 
      << "SumSquaresClass< int >: " << result << endl;
} 
