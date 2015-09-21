#include <iostream>

using namespace std; 

int main ()
{
  int i = 10, *iptr = &i; 
  cout << iptr << endl; 
  cout << *iptr << endl; 

  const char *cptr = "tricky"; 
  cout << cptr << endl;   // why? 
  cout << *cptr << endl;

  // but how to print the address of cptr 
  cout << static_cast<const void *>(cptr) << endl; 

  return 0;
}
