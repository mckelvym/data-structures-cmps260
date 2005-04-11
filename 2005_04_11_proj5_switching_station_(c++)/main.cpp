//  Author        : Mark McKelvy
//  CLID          : jmm0468
//  Class         : CMPS 260 - 3
//  Assignment    : Programming Assignment 5
//  Date Assigned : 2005, April 11
//  Due Date      : 2005, April 30, Saturday
//  Due Time      : 10:00 PM
//
//  Program Description: 
//  
//  --* Certification of Authenticity *--
//  I certify that this assignment is entirely my own work.

// main.cpp

#include<iostream>
#include<fstream>
#include<string>
#include "linkedList.h"

using namespace std;

const char cls[] = "cls";

bool readData(linkedList<int> & waiting, char filename[]);
// pre:   
//      * passed character to convert to lowercase if needed
// post:
//      * returns a lowercase letter 
char fixChoice(char c);
// post: 
//      * prompts the user to proceed
//      * returns true if yes, false if no
bool getch();
// post: 
//      * clears the screen
void cls();

int main(){
    char choice = 'x';
    linkedList<int> waiting;
   
    do{
    	cout << endl << endl;
    	cout << " * MAIN MENU *" << endl << endl;
    	cout << "1 - Open" << endl;
    	cout << "2 - " << endl;
    	cout << "x - Exit" << endl;
    	cout << endl << "> ";
    	cin >> choice;
    	choice = fixChoice(choice);
    	switch(choice){
            case '1':  // open new file
                    cls();
                    bool ok = false;
                    if(waiting.isEmptyList())
                        ok = true;
                    else{
                        cout << " ** LIST NOT EMPTY ** " << endl << endl;
                        ok = getch();
                        cls();
                    }
                    if(ok){
                        char filename[30];
                        cout << " * OPEN *" << endl << endl;
                        cout << "Filename: ";
                        cin >> filename;
                        cls();
                        if(readData(waiting, filename))
                            cout << " * OPEN: done. *";
                        else cout << " ** OPEN: failed. **";
                    }                        
                    break;
    		case 'x':
                	break;
            default:
                	cls();
                	cout << " *** OPTION NOT VALID ***";
                	break;
    	}
    }while(choice != 'x');
    
    return 0;
}

bool readData(linkedList<int> & waiting, char filename[]){
    ifstream fin;
    fin.open(filename);
    if(fin == NULL)
        return false;
    
    while(fin != NULL){
        fin >> waiting;
    }
    fin.close();
    return true;
}

char fixChoice(char c){
    if((c >= 65) && (c <= 90))
    	c += 32;
    return c;
}

bool getch(){
    char choice[30];
    cout << "Proceed (y/n)? ";
    cin >> choice;
    cout << endl;
    if(fixChoice(choice[0]) == 'y')
        return true;
    else return false;
}

void cls(){
    system(cls);
    //for(int x = 0; x < 25; x++)
    //    cout << endl;
}