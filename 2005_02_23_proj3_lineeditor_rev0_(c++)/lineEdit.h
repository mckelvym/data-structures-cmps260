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
	     // pre:  
	     // post: 
             lineEdit();
         // pre:  
	     // post: 
             lineEdit(int size, char * file);
         // pre:  
	     // post: 
             lineEdit(char * file);             
         // pre:  
	     // post: 
             char * getFilename();
         // pre:  
	     // post: 
             int getMaxLines();
         // pre:  
	     // post: 
             const arrayStringListType getDocument();             
         // pre:  
	     // post: 
             bool save(char * file);
         // pre:  
	     // post: 
             void setFilename(char * file);
         // pre:  
	     // post: 
             void show(int min, int max);
         // pre:  
	     // post: 
             void edit(int line);
         // pre:  
	     // post: 
             void cls();             
      private:
         // pre:  
	     // post: 
             void initializeNew();
             arrayStringListType * document;
             char * filename;
             int maxLines;
};

#endif
