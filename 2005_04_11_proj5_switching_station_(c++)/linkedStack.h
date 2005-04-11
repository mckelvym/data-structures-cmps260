//Header File: linkedStack.h

#ifndef H_StackType
#define H_StackType

#include <iostream>
#include <cassert>
#include "linkedNode.h"

using namespace std;

template<class Type>
class linkedStackType
{
public:
    friend ostream & operator<<(ostream & out, linkedStackType<Type> & l);
    friend istream & operator>>(istream & in, linkedStackType<Type> & l);
    
    const linkedStackType<Type>& operator=
                                (const linkedStackType<Type>&); 
      //Overload the assignment operator.
    void initializeStack();
      //Function to initialize the stack to an empty state. 
      //Postcondition: The stack elements are removed; 
      //               stackTop = NULL.
    bool isEmptyStack() const;
      //Function to determine whether the stack is empty.
      //Postcondition: Returns true if the stack is empty,
      //               otherwise returns false.
    bool isFullStack() const;
      //Function to determine whether the stack is full.
      //Postcondition: Returns false.

    void destroyStack();
      //Function to remove all the elements of the stack,  	 
      //leaving the stack in an empty state.
      //Postcondition: stackTop = NULL

    void push(const Type& identification, const Type& destination);
      //Function to add newItem to the stack.
      //Precondition: The stack exists and is not full.
      //Postcondition: The stack is changed and newItem 
      //               is added to the top of the stack.

    Type top() const;
      //Function to return the top element of the stack.
      //Precondition: The stack exists and is not empty.
      //Postcondition: If the stack is empty, the program 
      //               terminates; otherwise, the top element
      //               of the stack is returned.
    Type topID() const;
      //Function to return the top element's id.
      //Precondition: The stack exists and is not empty
      //Postcondition: If the stack is empty, the program
      //               terminates; otherwise, the top element's
      //               id is returned
    void pop();
      //Function to remove the top element of the stack.
      //Precondition: The stack exists and is not empty.
      //Postcondition: The stack is changed and the top element
      //               is removed from the stack.

    linkedStackType(); 
      //default constructor
      //Postcondition: stackTop = NULL
    linkedStackType(const linkedStackType<Type>& otherStack); 
      //copy constructor
    ~linkedStackType();
      //destructor
      //All the elements of the stack are removed from the stack.

private:
    nodeType<Type> *stackTop; //pointer to the stack

    void copyStack(const linkedStackType<Type>& otherStack); 
      //Function to make a copy of otherStack.
      //Postcondition: A copy of otherStack is created and
      //               assigned to this stack.
};

#endif
