#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "ListNode.h"
using namespace std;

template< typename NODETYPE >
class LinkedList 
{
 public:
  LinkedList(); // constructor
  ~LinkedList(); // destructor

  void insertAtFront( const NODETYPE & );
  void insertAtBack( const NODETYPE & );
  bool removeFromFront( NODETYPE & );
  bool removeFromBack( NODETYPE & );
  bool isEmpty() const;
  void print() const;

  /////////////////////////////////////////////////////////
  // new member functions for HW 5

  // overload array access operator 
  NODETYPE &operator[](int index) const;
  
  // Find the MAXIMAL SUM of values among all consecutive sub-lists 
  // of the linked list, assuming +, <, == are overloaded for NODETYPE
  NODETYPE maxSubSum() const; 

  // Sort the linked list in ascending order, 
  // assuming NODETYPE supports <, ==, etc.
  void sort(); 

  // In-place reversal of the linked list, i.e., don't create a new list
  // to perform the reversal, and use the list itself
  void reverse();        
  
  // Check whether the current list and the input l2 share any nodes or not 
  bool shared(const LinkedList< NODETYPE > &l2); 

  // Apply the function func to each element in the linked list
  void map(NODETYPE func(const NODETYPE &));

  // Keep only those nodes n where predicate(n) = true 
  void filter(bool predicate(const NODETYPE &)); 

  // Remove all duplicates from the list 
  void removeDup(); 
  
  //
  /////////////////////////////////////////////////////////

 private:
  ListNode< NODETYPE > *firstPtr;   // pointer to first node
  ListNode< NODETYPE > *lastPtr;    // pointer to last node

  // utility function to allocate new node
  ListNode< NODETYPE > *getNewNode( const NODETYPE & );
}; 


template< typename NODETYPE >
LinkedList< NODETYPE >::LinkedList() 
: firstPtr( 0 ), lastPtr( 0 ) 
{ 
  // empty body
} 

template< typename NODETYPE >
LinkedList< NODETYPE >::~LinkedList()
{
  if ( !isEmpty() ) // LinkedList is not empty
    {    
      ListNode< NODETYPE > *currentPtr = firstPtr;
      ListNode< NODETYPE > *tempPtr;

      while ( currentPtr != 0 ) // delete remaining nodes
	{  
	  tempPtr = currentPtr;
	  cout << tempPtr->data << '\n';
	  currentPtr = currentPtr->nextPtr;
	  delete tempPtr;
	} 
    } 
} 

// insert node at front of list
template< typename NODETYPE >
void LinkedList< NODETYPE >::insertAtFront( const NODETYPE &value )
{
  ListNode< NODETYPE > *newPtr = getNewNode( value ); // new node

  if ( isEmpty() )                 // LinkedList is empty
    firstPtr = lastPtr = newPtr;   // new list has only one node
  else // LinkedList is not empty
    {
      newPtr->nextPtr = firstPtr;  // point new node to previous 1st node
      firstPtr = newPtr;           // aim firstPtr at new node
    } 
} 

// insert node at back of list
template< typename NODETYPE >
void LinkedList< NODETYPE >::insertAtBack( const NODETYPE &value )
{
  // new node
  ListNode< NODETYPE > *newPtr = getNewNode( value ); 

  if ( isEmpty() )                // LinkedList is empty
    firstPtr = lastPtr = newPtr;  // new list has only one node
  else                            // LinkedList is not empty
    {
      lastPtr->nextPtr = newPtr;  // update previous last node
      lastPtr = newPtr;           // new last node
    }
} 

// delete node from front of list
template< typename NODETYPE >
bool LinkedList< NODETYPE >::removeFromFront( NODETYPE &value )
{
  if ( isEmpty() )                // LinkedList is empty
    return false;                 // delete unsuccessful
  else 
    {
      // hold tempPtr to delete
      ListNode< NODETYPE > *tempPtr = firstPtr; 

      if ( firstPtr == lastPtr )
	firstPtr = lastPtr = 0;   // no nodes remain after removal
      else
	firstPtr = firstPtr->nextPtr; // point to previous 2nd node

      value = tempPtr->data;      // return data being removed
      delete tempPtr;             // reclaim previous front node
      return true;                // delete successful
    } 
} 

// delete node from back of list
template< typename NODETYPE >
bool LinkedList< NODETYPE >::removeFromBack( NODETYPE &value )
{
  if ( isEmpty() )                // LinkedList is empty
    return false;                 // delete unsuccessful
  else 
    {
      ListNode< NODETYPE > *tempPtr = lastPtr; // hold tempPtr to delete

      if ( firstPtr == lastPtr )  // LinkedList has one element
	firstPtr = lastPtr = 0;   // no nodes remain after removal
      else 
	{
	  ListNode< NODETYPE > *currentPtr = firstPtr;

	  // locate second-to-last element            
	  while ( currentPtr->nextPtr != lastPtr )    
            currentPtr = currentPtr->nextPtr; // move to next node

	  lastPtr = currentPtr;    // remove last node
	  currentPtr->nextPtr = 0; // this is now the last node
	} 

      value = tempPtr->data;       // return value from old last node
      delete tempPtr;              // reclaim former last node
      return true;                 // delete successful
    }
} 

// is LinkedList empty?
template< typename NODETYPE > 
bool LinkedList< NODETYPE >::isEmpty() const 
{ 
  return firstPtr == 0; 
} 

// return pointer to newly allocated node
template< typename NODETYPE >
ListNode< NODETYPE > *LinkedList< NODETYPE >::getNewNode( const NODETYPE &value )
{
  return new ListNode< NODETYPE >( value );
}

// display contents of LinkedList
template< typename NODETYPE >
void LinkedList< NODETYPE >::print() const
{
  if ( isEmpty() )           // LinkedList is empty
    {
      cout << "The list is empty\n\n";
      return;
    }

  ListNode< NODETYPE > *currentPtr = firstPtr;

  cout << "The list is: ";

  while ( currentPtr != 0 ) // get element data
    {
      cout << currentPtr->data << ' ';
      currentPtr = currentPtr->nextPtr;
    } 

  cout << "\n\n";
} 

// overload array access operator 
template< typename NODETYPE >
NODETYPE & LinkedList< NODETYPE >::operator[](int index) const {
	ListNode <NODETYPE> *cur = firstPtr;

	for (int i = 0; i < index; i++) {
		cur = cur->nextPtr; 
	}

	return cur->data;
}

// Find the MAXIMAL SUM of values among all consecutive sub-lists 
// of the linked list, assuming +, <, == are overloaded for NODETYPE
template< typename NODETYPE >
NODETYPE LinkedList< NODETYPE >::maxSubSum() const {
	ListNode <NODETYPE> *cur = firstPtr;
	NODETYPE sum = 0, cur_max = 0;

	do {
		if (cur == 0) break;
		
		if ((cur->getData() + sum) <= 0) sum = 0;
		else sum = sum + cur->getData ();

		if (sum > cur_max) cur_max = sum;
		
		cur = cur->nextPtr;
	}
	while (1);

	return cur_max;
}

// Sort the linked list in ascending order, 
// assuming NODETYPE supports <, ==, etc.
template< typename NODETYPE >
void LinkedList< NODETYPE >::sort() {
	ListNode < NODETYPE > *cur = firstPtr->nextPtr;
	//LinkedList node = *(this);
	int i = 1;
	
	while (1) {
		int j = i;

		while (j >= 0 &&	(*this)[j - 1] > (*this)[j]) {
			NODETYPE temp = (*this)[j];
			(*this)[j] = (*this)[j - 1];
			(*this)[j - 1] = temp;

			j--;
		} //While prev is greater than the cur
		

		if (cur->nextPtr == 0) {
			break;
		}
		else {
			cur = cur->nextPtr;
			i++;
		}
	}
}

// In-place reversal of the linked list, i.e., don't create a new list
// to perform the reversal, and use the list itself
template< typename NODETYPE >
void LinkedList< NODETYPE >::reverse() {
	ListNode < NODETYPE > *firstCpy = firstPtr;
	ListNode < NODETYPE > *cur = firstPtr;
	ListNode < NODETYPE > *tempPtr = firstPtr->nextPtr;
	ListNode < NODETYPE > *tempPtrNext;

	while (1) {
		tempPtrNext = tempPtr->nextPtr;
		tempPtr->nextPtr = cur;
		cur = tempPtr;
		tempPtr = tempPtrNext;

		if (tempPtr == 0) {
			firstPtr = cur;
			break;
		}
	}

	firstCpy->nextPtr = 0;
	lastPtr = firstCpy;

}

// Check whether the current list and the input l2 share any nodes or not 
template< typename NODETYPE >
bool LinkedList< NODETYPE >::shared(const LinkedList< NODETYPE > &l2) {
	ListNode< NODETYPE > *cur = firstPtr;
	ListNode< NODETYPE > *cur2 = l2.firstPtr;

	while (cur != 0) {
		while (cur2 != 0) {
			if (cur->data == cur2->data) {
				return 1;
			}

			cur2 = cur2->nextPtr;
		}

		cur = cur->nextPtr;
		cur2 = l2.firstPtr;
	}

	return 0;
}

// Apply the function func to each element in the linked list
template< typename NODETYPE >
void LinkedList< NODETYPE >::map(NODETYPE func(const NODETYPE &)) {
	ListNode< NODETYPE > *cur = firstPtr;

	while (cur != 0) {
		cur->data = func (cur->data);
		cur = cur->nextPtr;
	}
}

// Keep only those nodes n where predicate(n) = true 
template< typename NODETYPE >
void LinkedList< NODETYPE >::filter(bool predicate(const NODETYPE &)) {	
	ListNode< NODETYPE > *cur = firstPtr;
	ListNode< NODETYPE > *prev = NULL;

	while (cur != 0) {
		if (!predicate(cur->data)) {
			if (prev != NULL) {
				prev->nextPtr = cur->nextPtr;
				
				delete cur;
				
				cur = prev->nextPtr;
			}
			else {
				firstPtr = cur->nextPtr;
				
				delete cur;

				cur = firstPtr;
			}
		}
		else {
			prev = cur;
			cur = cur->nextPtr;
		}

	}
}

// Remove all duplicates from the list 
template< typename NODETYPE >
void LinkedList < NODETYPE >::removeDup() {
	LinkedList < NODETYPE > uniq_ll;
	ListNode < NODETYPE > *uniq_cur = uniq_ll.firstPtr;
	
	ListNode < NODETYPE > *cur = firstPtr;
	ListNode < NODETYPE > *prev = NULL;

	while (cur != 0) {
		int valid = 1;
		uniq_cur = uniq_ll.firstPtr;

		while (uniq_cur != 0) {
			if (cur->data == uniq_cur->data) {
				prev->nextPtr = cur->nextPtr;
				delete cur;
				cur = prev->nextPtr;
				valid = 0;
				
				break;
			}

			uniq_cur = uniq_cur->nextPtr;
		} //Check if the current node already exists 	

		if (valid) {
			uniq_ll.insertAtFront (cur->data);
			prev = cur;
			cur = cur->nextPtr;
		} //If the current node doesnt exist, insert the uniq node value
	}
}

#endif
