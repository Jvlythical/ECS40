// Template Tree class definition.
#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <new>
#include "TreeNode.h"
#include "Queue.h"
using namespace std;

// Tree class-template definition
template< typename NODETYPE > class Tree
{
public:
   Tree(); // constructor
   void insertNode( const NODETYPE & );
   void preOrderTraversal() const;
   void inOrderTraversal() const;
   void postOrderTraversal() const;
   void levelOrderTraversal() const;

private:
   TreeNode< NODETYPE > *rootPtr;

   // utility functions
   void insertNodeHelper( TreeNode< NODETYPE > **, const NODETYPE & );
   void preOrderHelper( TreeNode< NODETYPE > * ) const;
   void inOrderHelper( TreeNode< NODETYPE > * ) const;
   void postOrderHelper( TreeNode< NODETYPE > * ) const;
}; 

// constructor
template< typename NODETYPE >
Tree< NODETYPE >::Tree() 
{ 
   rootPtr = 0; // indicate tree is initially empty 
} 

// insert node in Tree
template< typename NODETYPE >
void Tree< NODETYPE >::insertNode( const NODETYPE &value )
{ 
   insertNodeHelper( &rootPtr, value ); 
} 

// utility function called by insertNode; receives a pointer
// to a pointer so that the function can modify pointer's value
template< typename NODETYPE >
void Tree< NODETYPE >::insertNodeHelper( 
   TreeNode< NODETYPE > **ptr, const NODETYPE &value )
{
   // subtree is empty; create new TreeNode containing value
   if ( *ptr == 0 )  
      *ptr = new TreeNode< NODETYPE >( value );
   else // subtree is not empty
   {
      // data to insert is less than data in current node
      if ( value < ( *ptr )->data )
         insertNodeHelper( &( ( *ptr )->leftPtr ), value );
      else
      {
         // data to insert is greater than data in current node
         if ( value > ( *ptr )->data )
            insertNodeHelper( &( ( *ptr )->rightPtr ), value );
         else // duplicate data value ignored
            cout << value << " dup" << endl;
      } 
   } 
} 

// begin preorder traversal of Tree
template< typename NODETYPE > 
void Tree< NODETYPE >::preOrderTraversal() const
{ 
   preOrderHelper( rootPtr ); 
} 

// utility function to perform preorder traversal of Tree
template< typename NODETYPE >
void Tree< NODETYPE >::preOrderHelper( TreeNode< NODETYPE > *ptr ) const
{
   if ( ptr != 0 ) 
   {
      cout << ptr->data << ' '; // process node          
      preOrderHelper( ptr->leftPtr ); // traverse left subtree 
      preOrderHelper( ptr->rightPtr ); // traverse right subtree
   } 
} 

// begin inorder traversal of Tree
template< typename NODETYPE >
void Tree< NODETYPE >::inOrderTraversal() const
{ 
   inOrderHelper( rootPtr ); 
} 

// utility function to perform inorder traversal of Tree
template< typename NODETYPE >
void Tree< NODETYPE >::inOrderHelper( TreeNode< NODETYPE > *ptr ) const
{
   if ( ptr != 0 ) 
   {
      inOrderHelper( ptr->leftPtr ); // traverse left subtree  
      cout << ptr->data << ' '; // process node                
      inOrderHelper( ptr->rightPtr ); // traverse right subtree
   }
} 

// begin postorder traversal of Tree
template< typename NODETYPE >
void Tree< NODETYPE >::postOrderTraversal() const
{ 
   postOrderHelper( rootPtr ); 
} 

// utility function to perform postorder traversal of Tree
template< typename NODETYPE >
void Tree< NODETYPE >::postOrderHelper( 
   TreeNode< NODETYPE > *ptr ) const
{
   if ( ptr != 0 ) 
   {
      postOrderHelper( ptr->leftPtr ); // traverse left subtree  
      postOrderHelper( ptr->rightPtr ); // traverse right subtree
      cout << ptr->data << ' '; // process node                  
   } 
} 

// begin level-order traversal of Tree
template< typename NODETYPE >
void Tree< NODETYPE >::levelOrderTraversal() const
{ 
  Queue <TreeNode< NODETYPE> *> q; 

  TreeNode< NODETYPE > *tmpPtr = rootPtr;

  while ( tmpPtr != 0 ) {
    cout << tmpPtr->data << ' '; 
    
    if (tmpPtr->leftPtr != 0) {
      q.enqueue(tmpPtr->leftPtr); 
    } 
    
    if (tmpPtr->rightPtr != 0) {
      q.enqueue(tmpPtr->rightPtr);
    }
    
    if (!q.isQueueEmpty()) {
      q.dequeue(tmpPtr);
    }
    else {
      tmpPtr = 0; 
    }
  }
}

#endif
