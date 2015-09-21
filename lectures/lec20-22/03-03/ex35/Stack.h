// Template Stack class definition derived from class List.
#ifndef STACK_H
#define STACK_H

#include "List.h" // List class definition

template< typename STACKTYPE >
class Stack : private List< STACKTYPE >  // notice the use of private inheritance 
{
public:
   // push calls the List function insertAtFront
   void push( const STACKTYPE &data ) 
   { 
     insertAtFront( data ); 
   } 

   // pop calls the List function removeFromFront
   bool pop( STACKTYPE &data ) 
   { 
     return removeFromFront( data ); 
   } 

   // isStackEmpty calls the List function isEmpty
   bool isStackEmpty() const 
   { 
     return this->isEmpty();   // why the "this" is necessary? 
   } 
 
   // printStack calls the List function print
   void printStack() const 
   { 
     this->print();           // why this here too? 
   } 
}; 

#endif

