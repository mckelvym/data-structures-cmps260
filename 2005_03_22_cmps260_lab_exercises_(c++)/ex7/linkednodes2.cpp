// mark mckelvy
// jmm0468
// cs2603
// linkednodes2

#include <iostream>
#include <string>

using namespace std;

struct node 
{
	string name;
	string address;
	node * next;
};

node * getNew();
void output();
void deleteThem(node * temp);

node * head;
node * current;

int main() 
{
	head = getNew();
	head->next = getNew();
	head->next->next = getNew();
    
	output();

    	deleteThem(head);

    	return 0;
}

node * getNew(){
	node * temp = new node;
	cout << "Name? ";
	cin >> temp->name;
	cout << endl << "Address? ";
	cin >> temp->address;
	cout << endl;
	temp->next = NULL;
	
	return temp;
}

void output(){
	current = head;
	do{
		cout << "Name: " << current->name << endl;
		cout << "Address: " << current->address << endl;
		current = current->next;
	}while(current != NULL);
}

void deleteThem(node * temp){
	if(temp->next != NULL){
		deleteThem(temp->next);
	}
	delete temp;
}
