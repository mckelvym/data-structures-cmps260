// jmm0468
// cmps 260-3
// 2005 02 21
// lab excercise

#include<iostream>
#include "arrayListType.h"

using namespace std;

int main(){
	int temp;
	int temp2;
	arrayListType arraylist(20);
	
	cout << "Please enter 10 unique integers." << endl;
	for(int x = 0; x < 10; x++){
		cin >> temp;
		arraylist.insert(temp);
	}
	cout << endl << "The list is: ";
	arraylist.print();
	cout << endl << "Input a location you would like to view: ";
	cin >> temp;
	cout << endl << "The number at location " << temp << " is ";
	arraylist.retrieveAt(temp, temp);
	cout << temp << endl;
	cout << endl << "What location would you like to change? ";
	cin >> temp;
	cout << "What is the value for location " << temp << "? ";
	cin >> temp2;
	arraylist.replaceAt(temp, temp2);
	cout << endl << "The list is: ";
	arraylist.print();
	for(int x = 0; x < 12; x++){
		cin >> temp;
		arraylist.insert(temp);
	}
	return 0;
}
