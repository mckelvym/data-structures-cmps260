#include "bag.h"

using namespace std;

template <class X>
bag<X>::bag(){
	numberOfElements = 0;
	maxSize = 10;
	list = new X[10];
}

template <class X>
bag<X>::bag(int bagSize){
	numberOfElements = 0;
	maxSize = bagSize;
	list = new X[maxSize];
}

template <class X>
void bag<X>::listElements(){
	if(numberOfElements > 0){
		for(int x = 0; x < numberOfElements; x++){
			cout << list[x] << endl;
		}
	}
}

template <class X>
void bag<X>::put(X newOne){
	if(numberOfElements < maxSize){
		list[numberOfElements++] = newOne;
	}
}

template <class X>
X bag<X>::draw(){
	int element = rand() % numberOfElements;
	X temp = list[element];
	list[element] = list[numberOfElements - 1];
	list[numberOfElements - 1] = NULL;
	numberOfElements--;
	return temp;
}

template <class X>
bool bag<X>::IsEmpty(){
	if(numberOfElements == 0)
		return true;
	else return false;
}

template <class X>
bool bag<X>::IsFull(){
	if(numberOfElements == maxSize)
		return true;
	else return false;
}

template <class X>
int bag<X>::removeAll(X item){
	int total = 0;
	int counter = 0;
	X * list2 = new X[maxSize];
	
	for(int x = 0; x < numberOfElements; x++){
		if(list[x] != item){
			list2[counter] = list[x];
			counter++;
		}
		else total++;
	}
	list = list2;
	numberOfElements = counter;
	return total;
}

template <class X>
int bag<X>::getMaxSize(){
	return maxSize;
}

template <class X>
bag<X> operator+(const bag<X> & a, const bag<X> & b){
	int newSize = a.getMaxSize() + b.getMaxSize;
	bag<X> B(newSize);
	while(!a.IsEmpty())
		B.put(a.draw());
	while(!b.IsEmpty())
		B.put(b.draw());
	return B;
}	


