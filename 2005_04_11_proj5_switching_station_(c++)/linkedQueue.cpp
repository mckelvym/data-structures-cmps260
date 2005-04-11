#include <iostream>
#include <cassert>
#include "linkedQueue.h"

using namespace std;

template<class Type>
linkedQueueType<Type>::linkedQueueType() //default constructor
{
	queueFront = NULL; // set front to null
	queueRear = NULL;  // set rear to null
}


template<class Type>
bool linkedQueueType<Type>::isEmptyQueue() const
{
	return(queueFront == NULL);
}

template<class Type>
bool linkedQueueType<Type>::isFullQueue() const
{
	return false;
}

template<class Type>
void linkedQueueType<Type>::destroyQueue()
{
	nodeType<Type> *temp;

	while(queueFront!= NULL)	//while there are elements left
  								//in the queue
	{
	   temp = queueFront;    //set temp to point to the current node
	   queueFront = queueFront->link;  //advance first to the 
            							//next node
	   delete temp;       //deallocate memory occupied by temp
	}
    queueRear = NULL;  //set rear to NULL
}


template<class Type>
void linkedQueueType<Type>::initializeQueue()
{
     destroyQueue();
}

template<class Type>
void linkedQueueType<Type>::addQueue(const Type& identification, const Type& destination)
{
	nodeType<Type> *newNode;

	newNode = new nodeType<Type>;  //create the node
 	assert(newNode != NULL);

	newNode->id = identification;    //store the info
	newNode->dest = destination;
    newNode->link = NULL;		//initialize the link field to NULL
	
	if(queueFront == NULL)	      //if initially the queue is empty
    {
	   queueFront = newNode;
	   queueRear = newNode;
    }
    else				//add newNode at the end
    {
	   queueRear->link = newNode;
	   queueRear = queueRear->link;
    }
}//end addQueue

template<class Type>
Type linkedQueueType<Type>::front() const
{
	assert(queueFront != NULL);
   	return queueFront->dest; 
}

template<class Type>
Type linkedQueueType<Type>::back() const
{
	assert(queueRear!= NULL);
   	return queueRear->dest;
}

template<class Type>
void linkedQueueType<Type>::deQueue(){
    nodeType<Type> *newNode;
    
    if(queueFront != NULL){
        newNode = queueFront;
        queueFront = queueFront->link;
        delete newNode;
    }    
}

template<class Type>
void linkedQueueType<Type>::deleteQueue()
{
   nodeType<Type> *temp;
   
   if(!isEmptyQueue())
   {
   		temp = queueFront;       //make temp point to the first node
   		queueFront = queueFront->link; //advance queueFront 
   		delete temp;                  //delete the first node

   		if(queueFront == NULL)   //if after deletion the queue is empty
			queueRear = NULL;	 //set queueRear to NULL
   }
   else
		cerr<<"Cannot remove from an empty queue"<<endl;
}//end deleteQueue


template<class Type>
linkedQueueType<Type>::~linkedQueueType() //destructor
{
	nodeType<Type> *temp;

	while(queueFront != NULL)	  //while there are elements left in the queue
	{
	   temp = queueFront;         //set temp to point to the current node
	   queueFront = queueFront->link; //advance first to the next node
	   delete temp;          //deallocate memory occupied by temp
	}
   
	queueRear = NULL;  // set rear to null
}

template<class Type>
const linkedQueueType<Type>& linkedQueueType<Type>::operator=
                           (const linkedQueueType<Type>& otherQueue)
{
    if (this != &otherQueue) //avoid self-copy
    {
        copyQueue(otherQueue);
    }//end else

     return *this; 
}

	//copy constructor
template<class Type>
linkedQueueType<Type>::linkedQueueType(const linkedQueueType<Type>& otherQueue) 
{
    copyQueue(otherQueue);
}//end copy constructor


template<class Type>
void linkedQueueType<Type>::copyQueue
                   (const linkedQueueType<Type>& otherQueue) 
{
    nodeType<Type> *newNode; //pointer to create a node
    nodeType<Type> *current; //pointer to traverse the list

    if (queueFront != NULL) //if the list is nonempty, make it empty
       destroyQueue();

    if (otherQueue.queueFront == NULL) //otherList is empty
    {
        queueFront = NULL;
        queueRear = NULL;
    }
    else
    {
        current = otherQueue.queueFront; //current points to the 
                                   //list to be copied

        //copy the first node
        queueFront = new nodeType<Type>;  //create the node

        assert(queueFront != NULL);

        queueFront->id = current->id; //copy the info
        queueFront->dest = current->dest;
        queueFront->link = NULL;        //set the link field of 
                                   //the node to NULL
        queueRear = queueFront;              //make last point to the
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
            queueRear->link = newNode;  //attach newNode after last
            queueRear = newNode;        //make last point to
                                   //the actual last node
            current = current->link;   //make current point 
                                       //to the next node
        }//end while
    }//end else
}

template<class Type>
ostream & operator<<(ostream & out, linkedQueueType<Type> & l){
    
	nodeType<Type> *current; //pointer to traverse the list

	current = queueFront;  //set current so that it points to 
       			      //the first node
	while (current != NULL) //while more data to print
	{
	   out << current->id << ":" << current->dest << endl;
	   current = current->link;
	}    
    return out;
}

template<class Type>
istream & operator>>(istream & in, linkedQueueType<Type> & l){
    Type dest;
    Type id;
    in >> id >> dest;
    l.addQueue(id, dest);
    return in;
}
