//  Author        : Mark McKelvy
//  CLID          : jmm0468
//  Class         : CMPS 260 - 3
//  Assignment    : Programming Assignment 1
//  Date Assigned : 2005, February 21
//  Due Date      : 2005, March 10
//  Due Time      : 10:00 PM
//
//  Program Description: This program is a line editor that allows
//      a user to view parts of a document, and edit it one line
//      at a time. Additional functions include being able to save
//      the file, load a file from disk, or start a new file. 
//  
//  --* Certification of Authenticity *--
//  I certify that this assignment is entirely my own work.

// lineEditor.cpp

#include <iostream>
#include <fstream>
#include "lineEdit.h"

using namespace std;

// pre:  passed an object of type lineEdit
// post: displays a menu to the user, allowing them to start a 
//       new document, open an existing document, save the current
//       document, show a range of lines of the current document,
//       or edit a line of the document, and lastly, close the 
//       program
void menu(lineEdit le);
// pre:  passed an object of type lineEdit
// post: allows the user to start a new document, and to specify
//       the maximum number of lines
lineEdit nEw(lineEdit le);
// pre:  passed an object of type lineEdit
// post: allows the user to open a document from file
lineEdit open(lineEdit le);
// pre:  passed an object of type lineEdit
// post: prompts user for filename, and saves the document to file
bool save(lineEdit le);
// pre:  passed an object of type lineEdit
// post: prompts the user for a minimum and maximum range of lines
//       to be displayed and shows them to the user
void show(lineEdit le);
// pre:  passed an object of type lineEdit
// post: prompts the user for the line to edit, and allows
//       changing of the specified line
lineEdit edit(lineEdit le);
// pre:  passed an object of type lineEdit
// post: if a document is still open, the user is prompted to save,
//       otherwise the program exits
void exit(lineEdit le);
// pre:  passed an object of type lineEdit
// post: if a document is still open, this prompts the user to save it
void docStillOpen(lineEdit le);
// pre:  passed an integer assumed to be smaller than a second integer
// post: returns true if the first is less than the second, false otherwise
bool isMax(int min, int max);
// post: clears the screen (fills with blank lines)
void cls();

// global variable that keeps track if a document is open (true)
bool openDoc = false;

int main(){
	lineEdit le;
	// pass control of program to the menu
	menu(le);
	return 0;
}

void menu(lineEdit le){
	char choice[30];
	
	cls();
	cout << "\n *******************" << endl;
	cout << " *** LINE EDITOR ***" << endl;
	cout << " *******************" << endl << endl;
	cout << "1. New" << endl;
	cout << "2. Open" << endl;
	// if there is a document open, show these options
	if(openDoc){
	      cout << "3. Save" << endl;
	      cout << "4. Show" << endl;
	      cout << "5. Edit" << endl;
    }
    cout << endl << "0. Exit" << endl << endl;
	cout << "Choice? ";
	cin >> choice;
	cls();
	switch(choice[0]){
		case '1':
			menu(nEw(le));
            break;
		case '2':
			menu(open(le));
 			break;
		case '3':
		    if(openDoc)
                save(le);
			menu(le);
			break;
		case '4':
		    if(openDoc)
			    show(le);
			menu(le);
			break;
		case '5':
		    if(openDoc)
			    menu(edit(le));
		    else menu(le);
			break;
		case '0':
			exit(le);
			break;
		default:
			cout << endl;
			menu(le);
			break;
	}
}

lineEdit nEw(lineEdit le){
	int max;
	
	if(openDoc)
		docStillOpen(le);
    cout << endl << "* NEW *" << endl << endl;
    do{
        cout << "MAXLINES: ";
        cin >> max;
        if(max <= 0)
            cout << endl << "** ERROR: MAX < 0 **";
    }while(max <= 0);    
    le = lineEdit(max);
    openDoc = true;
    return le;
}

lineEdit open(lineEdit le){
    char filename[30];
    
    if(openDoc)
        docStillOpen(le);
    cout << endl << "* OPEN *" << endl << endl;
    cout << "FILENAME: ";
    cin >> filename;
    le = lineEdit(filename);
    openDoc = true;
    return le;
}

bool save(lineEdit le){
    char filename[30];
    
    cout << endl << "* SAVE *" << endl << endl;
    cout << endl << "FILENAME: ";
    cin >> filename;
    cout << endl;
    return le.save(filename);
}

void show(lineEdit le){ 
    int min = 0, max = -1;
    
    cout << endl << "* SHOW *" << endl << endl;
    do{
         do{
            do{
                 cout << "START: ";
                 cin >> min;
                 if(min <= 0)
                     cout << endl << "** ERROR: START < 1 **" << endl;                 
            }while(min <= 0);
            do{
                 cout << "END:   ";
                 cin >> max;
                 if(max > (le.getMaxLines()))
                     cout << endl << "** ERROR: END > MAXLINES **" << endl;
            }while(max > le.getMaxLines());    
            cout << endl;
         }while(!isMax(min,max));         
    }while((max - min) > 23);
    cls();
    le.show(min - 1, max - 1);
}

lineEdit edit(lineEdit le){
     int line;
     
     cout << endl << "* EDIT *" << endl << endl;
     do{
          cout << "LINE: ";
          cin >> line;
          if((line <= 0) || (line > le.getMaxLines()))
              cout << endl << "** ERROR: INVALID LINE **" << endl;
     }while((line <= 0) || (line > le.getMaxLines()));
     le.edit(line - 1);
     return le;     
}

void exit(lineEdit le){
     if(openDoc)
           docStillOpen(le);
     exit(0);
}

void docStillOpen(lineEdit le){
    char choice[30];
    
    cout << endl << "** DOCUMENT OPEN **" << endl;
    cout << endl << "SAVE (Y/N)? ";
    cin >> choice;
    if((choice[0] == 'y') || (choice[0] == 'Y')){
          save(le);
    }
    openDoc = false;
}

bool isMax(int min, int max){
    if(min <= max)
           return true;
    else return false;
}

void cls(){
    for(int x = 0; x < 25; x++)
        cout << endl;
}
