//Proxy class example from Ch 11 to hide implementation details

#include <iostream>
#include "Interface.h" // Interface class definition
using namespace std;

int main()
{
   Interface i(5);
 
   cout << "Interface contains: " << i.getValue() 
	<< " before setValue" << endl;

   i.setValue(10);

   cout << "Interface contains: " << i.getValue() 
	<< " after setValue" << endl;

   return 0; 

} 

