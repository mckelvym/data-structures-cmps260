#ifndef BAG_H
#define BAG_H

#include<iostream>

using namespace std;

template<class X>
class bag{    
	friend bag operator+(const bag & a, const bag & b);	
	public:
		bag();
		bag(int bagSize);
		void listElements();
		void put(X newOne);
		X draw();
		bool IsEmpty();
		bool IsFull();
		int removeAll(X item);
		int getMaxSize();
	private:
		X * list;
		int numberOfElements;
		int maxSize;	
};

#endif

