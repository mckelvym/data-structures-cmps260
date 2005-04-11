//Header file linkedQueue.h

#ifndef H_linkedQueue
#define H_linkedQueue

#include <iostream>
#include <cassert>
#include "linkedNode.h"

using namespace std;

template<class Type>
class linkedQueueType
{
public:
    friend ostream & operator<<(ostream & out, linkedQueueType<Type> & l);
    friend istream & operator>>(istream & in, linkedQueueType<Type> & l);
    
    const linkedQueueType<Type>& operator=
                    (const linkedQueueType<Type>&); 
      //Overload the assignment operator.

    bool isEmptyQueue() const;
      //Function to determine whether the queue is empty. 
      //Postcondition: Returns true if the queue is empty,
      //               otherwise returns false.
    bool isFullQueue() const;
      //Function to determine whether the queue is full. 
      //Postcondition: Returns true if the queue is full,
      //               otherwise returns false.

    void destroyQueue();
      //Function to delete all the elements from the queue.
      //Postcondition: queueFront = NULL; queueRear = NULL
    void initializeQueue();
      //Function to initialize the queue to an empty state.
      //Postcondition: queueFront = NULL; queueRear = NULL

    Type front() const;
      //Function to return the first element of the queue.
      //Precondition: The queue exists and is not empty.
      //Postcondition: If the queue is empty, the program 
      //               terminates; otherwise, the first 
      //               element of the queue is returned.  
    Type back() const;
      //Function to return the last element of the queue.
      //Precondition: The queue exists and is not empty.
      //Postcondition: If the queue is empty, the program 
      //               terminates; otherwise, the last 
      //               element of the queue is returned.

    void addQueue(const Type& identification, const Type& destination);
      //Function to add queueElement to the queue.
      //Precondition: The queue exists and is not full.
      //Postcondition: The queue is changed and queueElement
      //               is added to the queue.
    void deQueue();
      //Function to remove the front item from the queue.
      //Precondition: The queue exists and is not empty.
      //Postcondition: The front item of the queue is dequeued.
    void deleteQueue();
      //Function  to remove the first element of the queue.
      //Precondition: The queue exists and is not empty.
      //Postcondition: The queue is changed and the first 
      //               element is removed from the queue.

    linkedQueueType(); 
      //default constructor
    linkedQueueType(const linkedQueueType<Type>& otherQueue); 
      //copy constructor
    ~linkedQueueType(); //destructor

private:
    nodeType<Type> *queueFront; //pointer to the front of 
                                //the queue
    nodeType<Type> *queueRear;  //pointer to the rear of 
                                //the queue

    void linkedQueueType<Type>::copyQueue
                   (const linkedQueueType<Type>& otherQueue);
};


#endif
