// Template Queue class test program.
#include <iostream>
#include "Queue.h" // Queue class definition
using namespace std;

int main()
{
   Queue< int > intQueue; // create Queue of integers

   cout << "processing an integer Queue" << endl;

   // enqueue integers onto intQueue
   for ( int i = 0; i < 3; i++ ) 
   {
      intQueue.enqueue( i );
      intQueue.printQueue();
   }

   int dequeueInteger; // store dequeued integer

   // dequeue integers from intQueue
   while ( !intQueue.isQueueEmpty() ) 
   {
      intQueue.dequeue( dequeueInteger );
      cout << dequeueInteger << " dequeued" << endl;
      intQueue.printQueue();
   }

   Queue< double > doubleQueue; // create Queue of doubles
   double value = 1.1;

   cout << "processing a double Queue" << endl;

   // enqueue floating-point values onto doubleQueue
   for ( int j = 0; j < 3; j++ ) 
   {
      doubleQueue.enqueue( value );
      doubleQueue.printQueue();
      value += 1.1;
   }

   double dequeueDouble; // store dequeued double

   // dequeue floating-point values from doubleQueue
   while ( !doubleQueue.isQueueEmpty() ) 
   {
      doubleQueue.dequeue( dequeueDouble );
      cout << dequeueDouble << " dequeued" << endl;
      doubleQueue.printQueue();
   }
} 
