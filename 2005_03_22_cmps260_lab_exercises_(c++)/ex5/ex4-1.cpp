// jmm0468
// 260 - 3
// 3/7/05
// exc1

#include <iostream>
#include <string>
#include "arrayListType.h"

using namespace std;

int main(){
	int i;
	arrayListType<int> blackBoxInt;
	
	for(int x = 0; x < 5; x++){
		cout << "Integer? ";
		cin >> i;
		blackBoxInt.insert(i);
		cout << "List Size: " << blackBoxInt.listSize() << endl;
	}
	
	cout << "Ints in the list are: " << endl;
	blackBoxInt.print();
	
	cout << endl << "Input the value you want to replace: ";

	int tempValue;
	int tempIndex;

	cin >> tempValue;
	tempIndex = blackBoxInt.seqSearch(tempValue);
	cout << endl << "What value to replace with? ";
	cin >> tempValue;
	blackBoxInt.replaceAt(tempIndex, tempValue);
	
	cout << endl;
	
	cout << "Ints in the list are: " << endl;
	blackBoxInt.print();
	
	float f;
	arrayListType<float> floats;
	for(int x = 0; x < 5; x++){
		cout << "Enter float: ";
		cin >> f;
		floats.insert(f);
		cout << "List Size: " << floats.listSize() << endl;
	}
	
	cout << "Floats in the list are: " << endl;
	floats.print();
	
	cout << endl << "Input the value you want to delete: ";
	
	float tempFValue;
	
	cin >> tempFValue;
	floats.remove(tempFValue);
	
	cout << "Floats in list are: " << endl;
	floats.print();
	
	return 0;
}
