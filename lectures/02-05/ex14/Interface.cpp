// Implementation of class Interface--client receives this file only 
// as precompiled object code, keeping the implementation hidden.

#include "Interface.h" // Interface class definition
#include "Implementation.h" // Implementation class definition

Interface::Interface(int v) : ptr (new Implementation(v)) 
{                                   
   // empty body
} 

void Interface::setValue( int v ) 
{ 
   ptr->setValue( v ); 
} 

int Interface::getValue() const 
{ 
   return ptr->getValue(); 
} 

Interface::~Interface() 
{ 
   delete ptr; 
} 

