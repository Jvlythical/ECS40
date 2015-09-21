// test driver program for MergeSort

#include <iostream>
#include "MergeSort.h" 
using namespace std;

int main()
{
   // create object to perform merge sort
   MergeSort sortVector( 10 );
      
   cout << "Unsorted vector:" << endl;
   sortVector.displayElements();
   cout << endl << endl;
 
   sortVector.sort(); 

   cout << "Sorted vector:" << endl;
   sortVector.displayElements();
   cout << endl;
}

