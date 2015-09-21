// demonstrating a few additional string member functions
// 1) erase and replace
// 2) insert
#include <iostream>
#include <string>
using namespace std;

int main()
{
   // compiler concatenates all parts into one string
   string s( "The values in any left subtree"
	     "\nare less than the value in the"
	     "\nparent node and the values in"
	     "\nany right subtree are greater"
	     "\nthan the value in the parent node" );
   
   cout << "Original string:\n" << s << endl << endl;

   // remove all characters from (and including) location 62 
   // through the end of s
   s.erase( 62 );

   // output new string
   cout << "Original string after erase:\n" << s
      << "\n\nAfter first replacement:\n";
             
   int position = s.find( " " ); // find first space

   // replace all spaces with period
   while ( position != string::npos ) 
   {
      s.replace( position, 1, "." );
      position = s.find( " ", position + 1 );
   } 
    
   cout << s << "\n\nAfter second replacement:\n";
   
   position = s.find( "." ); // find first period

   // replace all periods with two semicolons
   // NOTE: this will overwrite characters
   while ( position != string::npos )
   {
      s.replace( position, 2, "xxxxx;;yyy", 5, 2 );
      position = s.find( ".", position + 1 );
   } 

   cout << s << endl;

   ////////////// 

   string string1( "beginning end" );
   string string2( "middle " );
   string string3( "12345678" );
   string string4( "xyz" );

   cout << "Initial strings:\nstring1: " << string1
      << "\nstring2: " << string2 << "\nstring3: " << string3
      << "\nstring4: " << string4 << "\n\n";

   // insert "middle" at location 10 in string1
   string1.insert( 10, string2 );

   // insert "xyz" at location 3 in string3
   string3.insert( 3, string4, 0, string::npos );

   cout << "Strings after insert:\nstring1: " << string1
      << "\nstring2: " << string2 << "\nstring3: " << string3
      << "\nstring4: " << string4 << endl;
} 

