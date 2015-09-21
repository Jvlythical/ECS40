#include <vector>
using namespace std;

class MergeSort
{
public:
   MergeSort( int );   // constructor initializes vector
   void sort();        // sort vector using merge sort
   void displayElements() const;   // display vector elements

private:
   int size;             // vector size
   vector< int > data;   // vector of ints
   void sortSubVector( int, int );       // sort subvector
   void merge( int, int, int, int );     // merge two sorted vectors
   void displaySubVector( int, int ) const;    // display subvector
}; 

