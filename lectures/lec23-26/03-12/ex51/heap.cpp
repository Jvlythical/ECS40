// Standard Library algorithms push_heap, pop_heap, 
// make_heap and sort_heap.

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator> 
using namespace std;

int main()
{
   const int SIZE = 10;
   int a[ SIZE ] = { 3, 100, 52, 77, 22, 31, 1, 98, 13, 40 };
   vector< int > v( a, a + SIZE ); // copy of a
   vector< int > v2;
   ostream_iterator< int > output( cout, " " );

   cout << "Vector v before make_heap:\n";
   copy( v.begin(), v.end(), output );

   make_heap( v.begin(), v.end() ); // create heap from vector v
   cout << "\nVector v after make_heap:\n";
   copy( v.begin(), v.end(), output );
   
   sort_heap( v.begin(), v.end() ); // sort elements with sort_heap
   cout << "\nVector v after sort_heap:\n";
   copy( v.begin(), v.end(), output );

   // perform the heapsort with push_heap and pop_heap
   cout << "\n\nArray a contains: ";
   copy( a, a + SIZE, output ); // display array a
   cout << endl;

   // place elements of array a into v2 and 
   // maintain elements of v2 in heap
   for ( int i = 0; i < SIZE; i++ ) 
   {
      v2.push_back( a[ i ] );
      push_heap( v2.begin(), v2.end() );      
      cout << "\nv2 after push_heap(a[" << i << "]): ";
      copy( v2.begin(), v2.end(), output );
   } 
   
   cout << endl;

   // remove elements from heap in sorted order
   for ( unsigned int j = 0; j < v2.size(); j++ ) 
   {
      cout << "\nv2 after " << v2[ 0 ] << " popped from heap\n";
      pop_heap( v2.begin(), v2.end() - j );
      copy( v2.begin(), v2.end(), output );
   } 

   cout << endl;
} 
