// jmm0468
// 260 - 3
// 3/7/05
// exc2

#include <iostream>
#include <string>
#include "arrayListType.h"
#include "person.h"

using namespace std;

int main(){
	Person i;
	arrayListType<Person> person;
	
	for(int x = 0; x < 2; x++){
		cout << "Person " << x+1 << endl;
		cout << "Name + [ENTER] + height + [ENTER] + weight + [ENTER]" << endl;
		cin >> i;
		person.insert(i);
		cout << "List Size: " << person.listSize() << endl;
	}
	
	cout << "Persons in the list are: " << endl;
	person.print();

	cout << endl;
	
	int tempIndex;
	string name;
	int height;
	int weight;
	
	cout << "Name to delete? ";
	cin >> name;
	cout << "\nHeight? ";
	cin >> height;
	cout << "\nWeight? ";
	cin >> weight;
	tempIndex = person.seqSearch(*(new Person(name, height, weight)));
	person.removeAt(tempIndex);
	cout << endl << "Persons in the list are: " << endl;
	person.print();
	
	cout << endl << "Please indicate the location to retrieve: ";
	cin >> tempIndex;
	
	person.retrieveAt(tempIndex, i);
	cout << endl << "The weight is: ";
	cout << i.getWeight() << endl;
	return 0;
}
