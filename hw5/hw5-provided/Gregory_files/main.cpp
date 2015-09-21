#include <iostream>
#include <string>
#include <sstream>
#include <typeinfo>
#include <limits>
#include <math.h>

#include "LinkedList.h"
#include "VectorList.h"

#include "TestVectorList.h"

using namespace std;

// display program instructions to user
void instructions()
{
   cout << "Enter one of the following:\n"
      << "  1 to insert at beginning of list\n" 
      << "  2 to insert at end of list\n" 
      << "  3 to delete from beginning of list\n" 
      << "  4 to delete from end of list\n" 
      << "  5 to find the max sub sum of list\n" 
      << "  6 to sort the list\n" 
      << "  7 to reverse the list\n" 
      << "  8 to check if a given list shares any nodes with the list\n" 
      << "  9 to map a function across the list\n"
      << "  10 to apply a filter predicate to the list\n"
      << "  11 to remove duplicates from the list\n"
      << "  12 to end list processing\n";
} 

template< typename T >
T square(const T &x )
{
   return x*x;
}

template<typename T>
bool isEven(const T &x )
{
   // const double twoDouble = 2.0;
   // const int two = 2;

   // if(typeid(x).name() == "double")
   return (x%2 == 0);
   // return false;
}


template<>
bool isEven<double>(const double &x )
{
   return (fmod(x,2.0) == 0.0);
   // return false;
}

// function to test a LinkedList
template< typename T >
void testLinkedList( LinkedList< T > &listObject, const string &typeName )
{
   cout << "Testing a LinkedList of " << typeName << " values\n";
   instructions();       // display instructions

   int choice;           // store user choice
   T value;              // store input value

   do                    // perform user-selected actions
   {
      cout << "? ";
      cin >> choice;

      switch ( choice ) 
      {
         case 1:         // insert at beginning
            cout << "Enter " << typeName << ": ";
            cin >> value;
            listObject.insertAtFront( value );
            listObject.print();
            break;
         case 2:         // insert at end
            cout << "Enter " << typeName << ": ";
            cin >> value;
            listObject.insertAtBack( value );
            listObject.print();
            break;
         case 3:         // remove from beginning
            if ( listObject.removeFromFront( value ) )
               cout << value << " removed from list\n";

            listObject.print();
            break;
         case 4:          // remove from end
            if ( listObject.removeFromBack( value ) )
               cout << value << " removed from list\n";

            listObject.print();
            break;
      }
   } while ( choice < 5 ); 

   cout << "End list test\n\n";
} 

// function to test a VectorList
template< typename T >
void testVectorList( VectorList< T > &listObject, const string &typeName )
{
   cout << "Testing a VectorList of " << typeName << " values\n";
   instructions();       // display instructions

   int choice;           // store user choice
   T value;              // store input value
   char input[100];         // list input 
   string str;
   //all the tests are run in the constructor
   //TestVectorList < int > testVector;
   

   do                    // perform user-selected actions
   {
      cout << "? ";
      cin >> choice;

      switch ( choice ) 
      {
         case 1:         // insert at beginning
            cout << "Enter " << typeName << ": ";
            cin >> value;
            listObject.insertAtFront( value );
            listObject.print();
            break;
         case 2:         // insert at end
            cout << "Enter " << typeName << ": ";
            cin >> value;
            listObject.insertAtBack( value );
            listObject.print();
            break;
         case 3:         // remove from beginning
            if ( listObject.removeFromFront( value ) )
               cout << value << " removed from list\n";

            listObject.print();
            break;
         case 4:          // remove from end
            if ( listObject.removeFromBack( value ) )
               cout << value << " removed from list\n";

            listObject.print();
            break;
         case 5:         // maxsubsum
            cout << listObject.maxSubSum();
            break;
         case 6:         // sort
            listObject.sort();
            listObject.print();
            break;
         case 7:          // reverse
            listObject.reverse();
            listObject.print();
            break;
         case 8:         // shared
         {
            cout << "Enter a list of " << typeName << "s: ";

            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline( std::cin, str);

            istringstream iss(str);

            VectorList<T> l2;
            do
            {
               T sub;
               iss >> sub;
               l2.insertAtBack(sub);
            }while(iss);

            cout << (listObject.shared(l2) ? "Shared nodes found" : "Shared nodes not found") << endl;
            break;
         }
         case 9:         // map
            cout << "Enter a function that takes " << typeName << "s: ";
            cin >> input;
            str = input;
            if(str == "square")
               listObject.map(square);
            listObject.print();
            break;
         case 10:         // filter
            cout << "Enter a predicate function that takes " << typeName << "s: ";
            cin >> input;
            str = input;
            if(str == "isEven")
               listObject.filter(isEven);
            listObject.print();
            break;
         case 11:          // removedups
            listObject.removeDup();
            listObject.print();
            break;
      }
   } while ( choice < 12 ); 

   cout << "End list test\n\n";
} 

int main()
{
   // // test LinkedList of int values
   // LinkedList< int > integerLinkedList;
   // testLinkedList( integerLinkedList, "integer" ); 

   // test VectorList of int values
   VectorList< int > integerVectorList;
   testVectorList( integerVectorList, "integer" ); 

   // // test LinkedList of double values
   // LinkedList< double > doubleLinkedList;
   // testLinkedList( doubleLinkedList, "double" ); 

   // test VectorList of double values
   VectorList< double > doubleVectorList;
   testVectorList( doubleVectorList, "double" ); 

   return 0;
} 

