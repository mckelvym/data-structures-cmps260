#include <iostream>
#include <cassert>
#include "linkedStack.h"

using namespace std;


template<class Type> //default constructor
linkedStackType<Type>::linkedStackType()
{
	stackTop = NULL;
}

template<class Type>
void linkedStackType<Type>::destroyStack()
{
	nodeType<Type> *temp; //pointer to delete the node

	while (stackTop != NULL)  //while there are elements in the stack
	{
	   temp = stackTop;      //set temp to point to the current node
	   stackTop = stackTop->link; //advance stackTop to the next node
	   delete temp;     //deallocate memory occupied by temp
	}
}// end destroyStack

template<class Type>
void linkedStackType<Type>:: initializeStack()
{
    destroyStack();
}

template<class Type>
bool linkedStackType<Type>::isEmptyStack() const
{
	return(stackTop == NULL);
}

template<class Type>
bool linkedStackType<Type>:: isFullStack() const
{
   return false;
}

template<class Type>
void linkedStackType<Type>::push(const Type& identification, const Type& destination)
{
   nodeType<Type> *newNode; //pointer to create the new node

   newNode = new nodeType<Type>; //create the node
   assert(newNode != NULL);

   newNode->id = identification;   //store newElement in the node
   newNode->dest = destination;
   newNode->link = stackTop;     //insert newNode before stackTop
   stackTop = newNode;          //set stackTop to point to the top node
} //end push


template<class Type>
Type linkedStackType<Type>::top() const
{
	assert(stackTop != NULL);	//if stack is empty,
								//terminate the program
   	return stackTop->dest;      //return the top element 
}//end top

template<class Type>
Type linkedStackType<Type>::topID() const{
    assert(stackTop != NUlL);
    
    return stackTop->id;
}

template<class Type>
void linkedStackType<Type>::pop()
{
   nodeType<Type> *temp;       //pointer to deallocate memory

   if (stackTop != NULL)
   {
   		temp = stackTop;            //set temp to point to the top node
   		stackTop = stackTop->link;  //advance stackTop to the next node
   		delete temp;	            //delete the top node
   }
   else
		cout << "Cannot remove from an empty stack." << endl;
}//end pop

template<class Type> 
void linkedStackType<Type>::copyStack
                       (const linkedStackType<Type>& otherStack)
{
    nodeType<Type> *newNode, *current, *last;

    if (stackTop != NULL) //if stack is nonempty, make it empty
        destroyStack();

    if (otherStack.stackTop == NULL)
        stackTop = NULL;
    else
    {
        current = otherStack.stackTop;  //set current to point
                                   //to the stack to be copied

            //copy the stackTop element of the stack 
        stackTop = new nodeType<Type>;   //create the node
        assert(stackTop != NULL);

        stackTop->id = current->id; //copy the info
        stackTop->dest = current->dest;
        stackTop->link = NULL;     //set the link field of the
                                   //node to NULL
        last = stackTop;      //set last to point to the node
        current = current->link;    //set current to point to
                                    //the next node

            //copy the remaining stack
        while (current != NULL)
        {
            newNode = new nodeType<Type>;
            assert(newNode!= NULL);

            newNode->id = current->id;
            newNode->dest = current->dest;
            newNode->link = NULL;
            last->link = newNode;
            last = newNode;
            current = current->link;
        }//end while
    }//end else
}

    //copy constructor
template<class Type>   
linkedStackType<Type>::linkedStackType(
                       const linkedStackType<Type>& otherStack) 
{
	stackTop = NULL;
	copyStack(otherStack);
}//end copy constructor

    //destructor
template<class Type> 
linkedStackType<Type>::~linkedStackType()
{
	destroyStack();
}//end destructor

    //overloading the assignment operator
template<class Type>   
const linkedStackType<Type>& linkedStackType<Type>::operator=
    			  (const linkedStackType<Type>& otherStack)
{ 
	if (this != &otherStack) //avoid self-copy
		copyStack(otherStack);

	return *this; 
}//end operator=


template<class Type>
ostream & operator<<(ostream & out, linkedStackType<Type> & l){
    
	nodeType<Type> *current; //pointer to traverse the list

	current = stackTop;  //set current so that it points to 
       			      //the first node
	while (current != NULL) //while more data to print
	{
	   out << current->id << ":" << current->dest << endl;
	   current = current->link;
	}    
    return out;
}

template<class Type>
istream & operator>>(istream & in, linkedStackType<Type> & l){
    Type dest;
    Type id;
    in >> id >> dest;
    l.push(id, dest);
    return in;
}
