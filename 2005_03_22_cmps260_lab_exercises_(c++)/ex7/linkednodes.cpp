// mark mckelvy
// jmm0468
// cs2603
// linkednodes

#include <iostream>
using namespace std;

struct node 
{
    int number;
    node *next;
};

void output(node * n);
void deleteThem(node * n);

int main() 
{
    node *n = new node;	
    n->number = 34;

    n->next = new node;
    n->next->number = 98;

    n->next->next = new node;
    n->next->next->number = 13;

    n->next->next->next = new node;
    n->next->next->next->number = 52;

    output(n);

    deleteThem(n);

    output(n);
    return 0;
}

void output(node * n){
	node * current;
	current = n;
	
	do{
		cout << current->number << endl;
		current = current->next;
	}while(current != NULL);
}

void deleteThem(node * n){
	if(n->next != NULL){
		deleteThem(n->next);
	}
	delete n;
}
