// Stack class template

#ifndef STACK_H
#define STACK_H

template< typename T >
class Stack 
{
public:
   Stack( int = 10 );       // default constructor (Stack size 10)

   ~Stack() 
   { 
      delete [] stackPtr;   // deallocate internal space for Stack
   } 

   bool push( const T & );  // push an element onto the Stack

   bool pop( T & );         // pop an element off the Stack

                            
   bool isEmpty() const     // determine whether Stack is empty
   { 
      return top == -1; 
   } 

   bool isFull() const      // determine whether Stack is full
   { 
      return top == size - 1; 
   } 

private:
   int size;                // # of elements in the stack
   int top;                 // location of the top element (-1 means empty)
   T *stackPtr;             // pointer to internal stack representation 
}; 

// constructor template
template< typename T >
Stack< T >::Stack( int s )
   : size( s > 0 ? s : 10 ),    // validate size
     top( -1 ),                 // Stack initially empty
     stackPtr( new T[ size ] )  // allocate memory for elements
{
   // empty body
} 

// push element onto Stack;
// if successful, return true; otherwise, return false
template< typename T >
bool Stack< T >::push( const T &pushValue )
{
   if ( !isFull() ) 
   {
      stackPtr[ ++top ] = pushValue;   // place item on Stack
      return true;                     // push successful
   } 

   return false;                       // push unsuccessful
} 

// pop element off Stack;
// if successful, return true; otherwise, return false
template< typename T > 
bool Stack< T >::pop( T &popValue )
{
   if ( !isEmpty() ) 
   {
      popValue = stackPtr[ top-- ];   // remove item from Stack
      return true;                    // pop successful
   }

   return false;                      // pop unsuccessful
} 

#endif
