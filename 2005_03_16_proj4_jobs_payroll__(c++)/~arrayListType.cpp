#include <iostream>
#include <cassert>
#include "arrayListType.h"

template <class elemType>
bool arrayListType<elemType>::isEmpty() const
{
	return (length == 0);
}

template <class elemType>
bool arrayListType<elemType>::isFull() const
{
	return (length == maxSize);
}

template <class elemType>
int arrayListType<elemType>::listSize() const
{
	return length;
}

template <class elemType>
int arrayListType<elemType>::maxListSize() const
{
	return maxSize;
}

template <class elemType>
void arrayListType<elemType>::print() const
{
	int i;

	for (i = 0; i < length; i++)
		cout << list[i] << " ";
	cout << endl;
}

template <class elemType>
bool arrayListType<elemType>::isItemAtEqual
                   (int location, const elemType& item)  const
{
	return(list[location] == item);
}

template <class elemType>
void arrayListType<elemType>::insertAt
                   (int location, const elemType& insertItem)
{
	int  i;

	if (location < 0 || location >= maxSize)
		cout << "The position of the item to be inserted "
			 << "is out of range." << endl;
	else
		if (length >= maxSize)  //list is full
			cout << "Cannot insert in a full list" << endl;
		else
		{
			for (i = length; i > location; i--)
				list[i] = list[i - 1];	//move the elements down

			list[location] = insertItem;	//insert the item at the 
 										//specified position

			length++;	//increment the length
		}
} //end insertAt


template <class elemType>
void arrayListType<elemType>::insertEnd(const elemType& insertItem)
{
	if (length >= maxSize)  //the list is full
		cout << "Cannot insert in a full list." << endl;
	else
	{
		list[length] = insertItem;	//insert the item at the end
		length++;	//increment length
	}
} //end insertEnd

template <class elemType>
void arrayListType<elemType>::removeAt(int location)
{
	int i;

	if (location < 0 || location >= length)
    	cout << "The location of the item to be removed "
			 << "is out of range." << endl;
	else
	{
   		for (i = location; i < length - 1; i++)
	 		list[i] = list[i+1];

		length--;
	}
} //end removeAt

template <class elemType>
void arrayListType<elemType>::retrieveAt
                     (int location, elemType& retItem)
{
	if (location < 0 || location >= length)
    	cout << "The location of the item to be retrieved is "
			 << "out of range." << endl;
	else
		retItem = list[location];
} // retrieveAt

template <class elemType>
void arrayListType<elemType>::replaceAt
                    (int location, const elemType& repItem)
{
	if (location < 0 || location >= length)
    	cout << "The location of the item to be replaced is "
			 << "out of range." << endl;
	else
		list[location] = repItem;

} //end replaceAt

template <class elemType>
void arrayListType<elemType>::clearList()
{
	length = 0;
} // end clearList

template <class elemType>
int arrayListType<elemType>::seqSearch(const elemType& item) const
{
	int loc;
	bool found = false;

	for (loc = 0; loc < length; loc++)
	   if ( list[loc] == item)
	   {
		  found = true;
		  break;
	   }

	if (found)
		return loc;
	else
		return -1;
} //end seqSearch

template <class elemType>
void arrayListType<elemType>::insert(const elemType& insertItem)
{
	int loc;

	if (length == 0)					 //list is empty
		list[length++] = insertItem; //insert the item and 
 									 //increment the length
	else
		if (length == maxSize)
			cout << "Cannot insert in a full list." << endl;
		else
		{
			loc = seqSearch(insertItem);

			if (loc == -1)   //the item to be inserted 
							//does not exist in the list
				list[length++] = insertItem;
			else
				cout << "the item to be inserted is already in "
 					 << "the list. No duplicates are allowed." << endl;
	}
} //end insert

template <class elemType>
void arrayListType<elemType>::remove(const elemType& removeItem)
{
	int loc;

	if (length == 0)
		cout << "Cannot delete from an empty list." << endl;
	else
	{
		loc = seqSearch(removeItem);

		if (loc != -1)
			removeAt(loc);
		else
			cout << "The tem to be deleted is not in the list."
				 << endl;
	}

} //end remove

template <class elemType>
arrayListType<elemType>::arrayListType(int size)
{
	if (size < 0)
	{
		cout << "The array size must be positive. Creating "
 			 << "an array of size 100. " << endl;

 	   maxSize = 100;
 	}
 	else
 	   maxSize = size;

	length = 0;

	list = new elemType[maxSize];
	assert(list != NULL);
}

template <class elemType>
arrayListType<elemType>::~arrayListType()
{
	delete [] list;
}


	//copy constructor
template <class elemType>
arrayListType<elemType>::arrayListType
                   (const arrayListType<elemType>& otherList)
{
   maxSize = otherList.maxSize;
   length = otherList.length;
   list = new elemType[maxSize]; 	//create the array
   assert(list != NULL);	//terminate if unable to allocate
 							//memory space

   for (int j = 0; j < length; j++)  //copy otherList
 	   list [j] = otherList.list[j];
}//end copy constructor

template <class elemType>
const arrayListType<elemType>& arrayListType<elemType>::operator=
			(const arrayListType<elemType>& otherList)
{
	if (this != &otherList)	//avoid self-assignment
	{				   
	   delete [] list;				   
	   maxSize = otherList.maxSize;		   
       length = otherList.length;			   
	  
       list = new elemType[maxSize];		   
	   assert(list != NULL);			   

       for (int i = 0; i < length; i++)	   
	   	    list[i] = otherList.list[i];	   
	}

    return *this;					   	   
}

