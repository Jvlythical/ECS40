#ifndef VECTORLIST_H
#define VECTORLIST_H

#include <iostream>
#include <vector>
using namespace std;

template< typename NODETYPE >
class VectorList 
{
 public:
  VectorList(); // constructor
  ~VectorList(); // destructor

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
  void sortHelper(int left, int right);
  
  void swap(int i, int j);
  
  int  size() const;

  // In-place reversal of the linked list, i.e., don't create a new list
  // to perform the reversal, and use the list itself
  void reverse();        

  // Check whether the current list and the input l2 share any nodes or not 
  bool shared(const VectorList< NODETYPE > &l2) const; 
  
  // Apply the function func to each element in the linked list
  void map(NODETYPE func(const NODETYPE &));
  
  // Keep only those nodes n where predicate(n) = true 
  void filter(bool predicate(const NODETYPE &)); 

  // Remove all duplicates from the list 
  void removeDup(); 

  //
  /////////////////////////////////////////////////////////

 private:
  vector< NODETYPE > *vList;  // list data as a vector
}; 


template< typename NODETYPE > 
VectorList< NODETYPE >::VectorList()  
  // Fill in the missing code 
{  
  vList = new vector<NODETYPE>();
}  

template< typename NODETYPE > 
VectorList< NODETYPE >::~VectorList() 
{ 
  // Fill in the missing code 
  delete(vList);
}  

// insert node at front of list
template< typename NODETYPE >
void VectorList< NODETYPE >::insertAtFront( const NODETYPE &value )
{
  vList->insert(vList->begin(), value); 
} 

// insert node at back of list
template< typename NODETYPE >
void VectorList< NODETYPE >::insertAtBack( const NODETYPE &value )
{
  // Fill in the missing code 
  vList->push_back(value);
} 

// delete node from front of list
template< typename NODETYPE >
bool VectorList< NODETYPE >::removeFromFront( NODETYPE &value )
{
  if(isEmpty())
    return false;
  value = vList->at(0);
  vList->erase(vList->begin());
  return true;
} 

// delete node from back of list
template< typename NODETYPE >
bool VectorList< NODETYPE >::removeFromBack( NODETYPE &value )
{ 
  if(isEmpty())
    return false;
  value = vList->at(vList->size()-1);
  vList->pop_back();
  return true;
} 

// is VectorList empty?
template< typename NODETYPE > 
bool VectorList< NODETYPE >::isEmpty() const 
{  
  return vList->empty(); 
} 

// display contents of VectorList
template< typename NODETYPE >
void VectorList< NODETYPE >::print() const
{
  // Fill in the missing code 
  if ( isEmpty() )           // VectorList is empty
  {
     cout << "The list is empty\n\n";
     return;
  }
  cout << "The list is: ";
  for (typename vector<NODETYPE>::iterator it = vList->begin() ; it != vList->end(); ++it)
    std::cout << ' ' << *it;
  cout << "\n\n";
} 

  // overload array access operator 
  template< typename NODETYPE >
  NODETYPE & VectorList< NODETYPE >::operator[](int index) const
  {
    return vList->at(index);
  }

  // Find the MAXIMAL SUM of values among all consecutive sub-lists 
  // of the linked list, assuming +, <, == are overloaded for NODETYPE
  template< typename NODETYPE >
  NODETYPE VectorList< NODETYPE >::maxSubSum() const
  {
      NODETYPE maxSum = 0;
			int length = vList->size();

      for (int i = -1; i < length; ++i)
      {
        NODETYPE sum = 0;
        for (int j = i+1; j < length; ++j)
        {
          sum += (*vList)[j];
          if(sum > maxSum)
            maxSum = sum;
        }
      }
      return maxSum;
  } 

  // Sort the linked list in ascending order, 
  // assuming NODETYPE supports <, ==, etc.
  template< typename NODETYPE >
  void VectorList< NODETYPE >::sort()
  { //bubble sort
    for (int i = 0; i < size(); i++)
      for (int j = 0; j < size() - 1; j++)
        if ((*vList)[j] > (*vList)[j+1]){
          swap(j,j+1);
        } 
  } 

  template< typename NODETYPE >
  void VectorList< NODETYPE >::swap(int i, int j)
  {
    NODETYPE tmp = (*vList)[i];
    (*vList)[i] = (*vList)[j];
    (*vList)[j] = tmp;
  }

  template< typename NODETYPE >
  int VectorList< NODETYPE >::size() const
  {
    return vList->size();
  }

  // In-place reversal of the linked list, i.e., don't create a new list
  // to perform the reversal, and use the list itself
  template< typename NODETYPE >
  void VectorList< NODETYPE >::reverse()
  {
  	int length = vList->size();

    for (int i = 0; i < length / 2; i++)
      swap(i, length - 1 - i);
  }    
  
  // Check whether the current list and the input l2 share any nodes or not 
  template< typename NODETYPE >
  bool VectorList< NODETYPE >::shared(const VectorList< NODETYPE > &l2) const
  {
    for (int i = 0; i < size(); ++i)
      for (int j = 0; j < l2.size(); ++j)
        if((*vList)[i] == l2[j])
          return true;
    return false;
  }

  // Apply the function func to each element in the linked list
  template< typename NODETYPE >
  void VectorList< NODETYPE >::map(NODETYPE func(const NODETYPE &))
  {
    for(int i = 0; i < size(); ++i)
      (*vList)[i] = func((*vList)[i]);
  }

  // Keep only those nodes n where predicate(n) = true 
  template< typename NODETYPE >
  void VectorList< NODETYPE >::filter(bool predicate(const NODETYPE &))
  {
    //cout << size() << endl;
    for(int i = 0; i < size(); i++)
    {
      if(!predicate(((*vList)[i])))
        vList->erase(vList->begin()+(i--));
    }
  }

  // Remove all duplicates from the list 
  template< typename NODETYPE >
  void VectorList< NODETYPE >::removeDup()
  {
    for(int i = 0; i < size()-1; i++)
      for(int j = 1; j < size(); j++)
        if((*vList)[i] == (*vList)[j])
          vList->erase(vList->begin()+j);
  }


#endif
