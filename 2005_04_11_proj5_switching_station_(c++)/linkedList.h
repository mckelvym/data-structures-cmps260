#ifndef H_LinkedListType
#define H_LinkedListType

#include <iostream>
#include <cassert>
#include "linkedNode.h"

using namespace std;

template<class Type>
class linkedListType
{
public:
    friend ostream & operator<<(ostream & out, linkedListType<Type> & l);
    friend istream & operator>>(istream & in, linkedListType<Type> & l);
    
    const linkedListType<Type>& operator=
                         (const linkedListType<Type>&);  
      //Overload the assignment operator.
    void initializeList(); 
      //Initialize the list to an empty state.
      //Postcondition: first = NULL, last = NULL, count = 0;
    bool isEmptyList() const;
      //Function to determine whether the list is empty. 
      //Postcondition: Returns true if the list is empty,
      //               otherwise it returns false.
    void print() const;
      //Function to output the data contained in each node.
      //Postcondition: none
    int length() const;
      //Function to return the number of nodes in the list.
      //Postcondition: The value of count is returned.
    void destroyList();
      //Function to delete all the nodes from the list.
      //Postcondition: first = NULL, last = NULL, count = 0;
    Type front() const; 
      //Function to return the first element of the list.
      //Precondition: The list must exist and must not be 
      //              empty.
      //Postcondition: If the list is empty, the program
      //               terminates; otherwise, the first 
      //               element of the list is returned.
    Type back()const; 
      //Function to return the last element of the list.
      //Precondition: The list must exist and must not be 
      //              empty.
      //Postcondition: If the list is empty, the program
      //               terminates; otherwise, the last  
      //               element of the list is returned.
    Type frontID() const;
      // Function to return the first element's id in the list
      // Precondition: The list must exist and must not be empty
      // Postcondition: If the list is empty, the program terminates
      //                otherwise the first element's id is returned
    Type backID() const;
      // Function to return the last element's id in the list
      // Precondition: The list must exist and must not be empty
      // Postcondition: If the list is empty, the program terminates
      //                otherwise the last element's id is returned
    bool search(const Type& searchID) const;
      //Function to determine whether searchItem is in the list.
      //Postcondition: Returns true if searchItem is in the 
      //               list, otherwise the value false is 
      //               returned.

    void insertFirst(const Type& identification, const Type& destination);
      //Function to insert newItem at the beginning of the list.
      //Postcondition: first points to the new list, newItem is
      //               inserted at the beginning of the list,
      //               last points to the last node in the list, 
      //               and count is incremented by 1.

    void insertLast(const Type& identification, const Type& destination);
      //Function to insert newItem at the end of the list.
      //Postcondition: first points to the new list, newItem 
      //               is inserted at the end of the list,
      //               last points to the last node in the list,
      //               and count is incremented by 1.

    void deleteNode(const Type& identification);
      //Function to delete deleteItem from the list.
      //Postcondition: If found, the node containing 
      //               deleteItem is deleted from the list.
      //               first points to the first node, last
      //               points to the last node of the updated 
      //               list, and count is decremented by 1.


    linkedListType(); 
      //default constructor
      //Initializes the list to an empty state.
      //Postcondition: first = NULL, last = NULL, count = 0; 

    linkedListType(const linkedListType<Type>& otherList); 
         //copy constructor

    ~linkedListType();   
      //destructor
      //Deletes all the nodes from the list.
      //Postcondition: The list object is destroyed. 

protected:
    int count;   //variable to store the number of 
                 //elements in the list
    nodeType<Type> *first; //pointer to the first node of the list
    nodeType<Type> *last;  //pointer to the last node of the list

private: 
    void copyList(const linkedListType<Type>& otherList); 
      //Function to make a copy of otherList.
      //Postcondition: A copy of otherList is created and
      //               assigned to this list.
};

#endif
