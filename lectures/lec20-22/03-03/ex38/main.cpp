// Tree class test program.
#include <iostream>
#include <iomanip>
#include "Tree.h" // Tree class definition
using namespace std;

int main()
{
   Tree< int > intTree; // create Tree of int values
   int intValue;

   cout << "Enter 10 integer values:\n";

   // insert 10 integers to intTree
   for ( int i = 0; i < 10; i++ ) 
   {
      cin >> intValue;
      intTree.insertNode( intValue );
   }

   cout << "\nPreorder traversal\n";
   intTree.preOrderTraversal();

   cout << "\nInorder traversal\n";
   intTree.inOrderTraversal();

   cout << "\nPostorder traversal\n";
   intTree.postOrderTraversal();

   cout << "\nLevelorder traversal\n";
   intTree.levelOrderTraversal();

   Tree< double > doubleTree; // create Tree of double values
   double doubleValue;

   cout << fixed << setprecision( 1 )
      << "\n\n\nEnter 10 double values:\n";

   // insert 10 doubles to doubleTree
   for ( int j = 0; j < 10; j++ ) 
   {
      cin >> doubleValue;
      doubleTree.insertNode( doubleValue );
   }

   cout << "\nPreorder traversal\n";
   doubleTree.preOrderTraversal();

   cout << "\nInorder traversal\n";
   doubleTree.inOrderTraversal();

   cout << "\nPostorder traversal\n";
   doubleTree.postOrderTraversal();

   cout << "\nLevelorder traversal\n";
   doubleTree.levelOrderTraversal();

   cout << endl;
} 
