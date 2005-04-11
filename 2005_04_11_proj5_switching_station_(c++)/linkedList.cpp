#include <iostream>
#include <cassert>
#include "linkedList.h"

using namespace std;

template<class Type>
bool linkedListType<Type>::isEmptyList() const
{
	return(first == NULL);
}

template<class Type>
linkedListType<Type>::linkedListType() //default constructor
{
	first = NULL;
	last = NULL;
 	count = 0;
}

template<class Type>
void linkedListType<Type>::destroyList()
{
    nodeType<Type> *temp;   //pointer to deallocate the memory
                            //occupied by the node
    while (first != NULL)   //while there are nodes in the list
    {
        temp = first;        //set temp to the current node
        first = first->link; //advance first to the next node
        delete temp;        //deallocate the memory occupied by temp
    }
    last = NULL; //initialize last to NULL; first has already
                 //been set to NULL by the while loop
    count = 0;
}
	
template<class Type>
void linkedListType<Type>::initializeList()
{
	destroyList(); //if the list has any nodes, delete them
}

template<class Type>
void linkedListType<Type>::print() const
{
	nodeType<Type> *current; //pointer to traverse the list

	current = first;  //set current so that it points to 
       			      //the first node
	while (current != NULL) //while more data to print
	{
	   cout << "ID:" << current->id << " DEST:" << current->dest << " ";
	   current = current->link;
	}
}//end print


template<class Type>
int linkedListType<Type>::length() const
{
    return count;
}  //end length

template<class Type>
Type linkedListType<Type>::front() const
{   
    assert(last != NULL);
    return first->dest; //return the info of the first node	
}//end front

template<class Type>
Type linkedListType<Type>::back() const
{   
    assert(last != NULL);
    return last->dest; //return the info of the first node	
}//end back

template<class Type>
Type linkedListType<Type>::frontID() const{
    assert(last != NULL);
    return first->id;
}

template<class Type>
Type linkedListType<Type>::backID() const{
    assert(last != NULL);
    return last->id;
}

template<class Type>
bool linkedListType<Type>::search(const Type& searchID) const
{
    nodeType<Type> *current; //pointer to traverse the list
    bool found = false;
    
    current = first; //set current to point to the first 
                     //node in the list

    while (current != NULL && !found)    //search the list
        if (current->id == searchID) //searchItem is found
            found = true;
        else
            current = current->link; //make current point to
                                     //the next node
    return found; 
}//end search

template<class Type>
void linkedListType<Type>::insertFirst(const Type& identification, const Type& destination)
{
   nodeType<Type> *newNode; //pointer to create the new node

   newNode = new nodeType<Type>; //create the new node

   assert(newNode != NULL);      //if unable to allocate memory, 
                                 //terminate the program

   newNode->id = identification; 	   //store the new item in the node
   newNode->dest = destination;
   newNode->link = first;        //insert newNode before first
   first = newNode;              //make first point to the 
                                 //actual first node
   count++; 			   //increment count

   if (last == NULL)   //if the list was empty, newNode is also 
                      //the last node in the list
      last = newNode;
}//end insertFirst

template<class Type>
void linkedListType<Type>::insertLast(const Type& identification, const Type& destination)
{
   nodeType<Type> *newNode; //pointer to create the new node

   newNode = new nodeType<Type>; //create the new node

   assert(newNode != NULL);	//if unable to allocate memory, 
 					//terminate the program

   newNode->id = identification;      //store the new item in the node
   newNode->dest = destination;
   newNode->link = NULL;         //set the link field of newNode
         				   //to NULL

   if (first == NULL)  //if the list is empty, newNode is 
     			    //both the first and last node
   {
	  first = newNode;
	  last = newNode;
	  count++;		//increment count
   }
   else     //the list is not empty, insert newNode after last
   {
	last->link = newNode; //insert newNode after last
	last = newNode;   //make last point to the actual last node
      count++;		//increment count
   }
}//end insertLast


template<class Type>
void linkedListType<Type>::deleteNode(const Type& identification)
{
    nodeType<Type> *current; //pointer to traverse the list
    nodeType<Type> *trailCurrent; //pointer just before current
    bool found;

    if (first == NULL)    //Case 1; the list is empty. 
        cout << "Cannot delete from an empty list."
             << endl;
    else
    {
        if (first->id == identification) //Case 2 
        {
            current = first;
            first = first->link;
            count--;
            if (first == NULL)    //the list has only one node
                last = NULL;
            delete current;
        }
        else //search the list for the node with the given info
        {
            found = false;
            trailCurrent = first;  //set trailCurrent to point
                                   //to the first node
            current = first->link; //set current to point to 
                                   //the second node

            while (current != NULL && !found)
            {
                if (current->id != identification) 
                {
                    trailCurrent = current;
                    current = current-> link;
                }
                else
                    found = true;
            }//end while

            if (found) //Case 3; if found, delete the node
            {
                trailCurrent->link = current->link;
                count--;

                if (last == current)   //node to be deleted 
                                       //was the last node
                    last = trailCurrent; //update the value 
                                         //of last
                delete current;  //delete the node from the list
            }
            else
                cout << "The item to be deleted is not in "
                     << "the list." << endl;
        }//end else
    }//end else
}//end deleteNode

template<class Type>
void linkedListType<Type>::copyList
                   (const linkedListType<Type>& otherList) 
{
    nodeType<Type> *newNode; //pointer to create a node
    nodeType<Type> *current; //pointer to traverse the list

    if (first != NULL) //if the list is nonempty, make it empty
       destroyList();

    if (otherList.first == NULL) //otherList is empty
    {
        first = NULL;
        last = NULL;
        count = 0;
    }
    else
    {
        current = otherList.first; //current points to the 
                                   //list to be copied
        count = otherList.count;

            //copy the first node
        first = new nodeType<Type>;  //create the node

        assert(first != NULL);

        first->id = current->id; //copy the info
        first->dest = current->dest;
        first->link = NULL;        //set the link field of 
                                   //the node to NULL
        last = first;              //make last point to the
                                   //first node
        current = current->link;     //make current point to
                                     //the next node

           //copy the remaining list
        while (current != NULL)
        {
            newNode = new nodeType<Type>;  //create a node

            assert(newNode != NULL);

            newNode->id = current->id; //copy the info
            newNode->dest = current->dest;
            newNode->link = NULL;       //set the link of 
                                        //newNode to NULL
            last->link = newNode;  //attach newNode after last
            last = newNode;        //make last point to
                                   //the actual last node
            current = current->link;   //make current point 
                                       //to the next node
        }//end while
    }//end else
}//end copyList

template<class Type>
linkedListType<Type>::~linkedListType() //destructor
{
   destroyList();
}//end destructor

template<class Type>
linkedListType<Type>::linkedListType
            	    (const linkedListType<Type>& otherList) 
{
   	first = NULL;
    copyList(otherList);
}//end copy constructor

         //overload the assignment operator
template<class Type>
const linkedListType<Type>& linkedListType<Type>::operator=
                      (const linkedListType<Type>& otherList)
{ 
    if (this != &otherList) //avoid self-copy
    {
        copyList(otherList);
    }//end else

     return *this; 
}

template<class Type>
ostream & operator<<(ostream & out, linkedListType<Type> & l){
    
	nodeType<Type> *current; //pointer to traverse the list

	current = first;  //set current so that it points to 
       			      //the first node
	while (current != NULL) //while more data to print
	{
	   out << current->id << ":" << current->dest << endl;
	   current = current->link;
	}    
    return out;
}

template<class Type>
istream & operator>>(istream & in, linkedListType<Type> & l){
    Type dest;
    Type id;
    in >> id >> dest;
    l.insertLast(id, dest);
    return in;
}
