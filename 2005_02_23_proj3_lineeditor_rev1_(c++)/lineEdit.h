// jmm0468
// cmps260 s3
// lineEdit.h

#ifndef H_lineEdit
#define H_lineEdit

#include <iostream>
#include <fstream>
#include <string>
#include "arrayStringListType.h"

using namespace std;

class lineEdit{
      public:
	     // post: creates a new document with 100 lines max
             lineEdit();
         // pre:  passed an integer specifying max lines
	     // post: creates a new document with 'size' lines max
             lineEdit(int size);
         // pre:  passed a character array as the name of a file
	     // post: reads data from the specified file into a 
	     //       new document
             lineEdit(char * file);             
	     // post: returns an integer representing the max lines
	     //       allowed for the current document
             int getMaxLines();
	     // post: returns an arrayStringListType (document)
	     //       copy of the current document
             const arrayStringListType getDocument();             
         // pre:  passed a character array as the name of a file
	     // post: saves the document data to the specified file
             bool save(char * file);
         // pre:  passed an integer min, and an integer max
         //       representing a range of lines to display
	     // post: displays the document lines min through max
	     //       to the user, with line numbers
             void show(int min, int max);
         // pre:  passed an integer line, representing the line
         //       to be edited
	     // post: displays the line to be edited to the user, and
	     //       waits for the user to enter a new line as the
	     //       replacement
             void edit(int line);
	     // post: clears the screen (with blank lines)
             void cls();             
      private:
	     // post: initializes all the of blank lines in the document
	     //       if a new document is started
             void initializeNew();
         // the document
             arrayStringListType * document;
         // max lines in the document
             int maxLines;
};

#endif
