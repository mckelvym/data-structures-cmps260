// jmm0468
// cmps260 s3
// lineEdit.cpp

#include <iostream>
#include <string>
#include "arrayStringListType.h"
#include "lineEdit.h"

using namespace std;

lineEdit::lineEdit(){
    maxLines = 100;
    strcpy(filename,"default.txt");
    document = new arrayStringListType(100);
    initializeNew();
}    
lineEdit::lineEdit(int size, char * file){
    maxLines = size;
    filename = file;
    document = new arrayStringListType(size);
    initializeNew();    
}
lineEdit::lineEdit(char * file){
    ifstream fin;
    string s;
    filename = file;
    //strcpy(filename,file);
    fin.open(filename);
    fin >> maxLines;
    document = new arrayStringListType(maxLines);
    for(int x = 0; x < maxLines; x++){
        fin >> s;
        document[0].insertEnd(s);
    }
    fin.close();
}

bool lineEdit::save(char * file){
    ofstream fout;
    string s;
    
    filename = file;
    fout.open(file);
    fout << maxLines << endl;
    for(int x = 0; x < maxLines; x++){
        if(x < document[0].listSize()){
            document[0].retrieveAt(x,s);
            fout << s << endl;
        }
        else{
            fout << endl;
        }        
    }
    fout.close();
    return true;    
}

char * lineEdit::getFilename(){
    return filename;
}

void lineEdit::setFilename(char * file){
    filename = file;    
    //strcpy(filename,file);
}

int lineEdit::getMaxLines(){
    return maxLines;
}

void lineEdit::show(int min, int max){
    char choice[30];
    string s;
    
    cout << endl;
    for(int x = min; x <= max; x++){
        document[0].retrieveAt(x,s);
        cout << x + 1;
        if((x >= 0) && (x < 10))
             cout << "    ";
        else if((x > 9) && (x < 100))
             cout << "   ";
        else if((x > 99) && (x < 1000))
             cout << "  ";
        else if(x > 999)
             cout << " ";
        cout << s << endl;
    }
    cout << endl << "Type 'b' for back. ";
    cin >> choice;
    if(!((choice[0] == 'b') || (choice[0] == 'B'))){
        cls();
        show(min,max);   
    }    
}    

void lineEdit::edit(int line){
    char  c[75];
    string s;
    
    cls();
    cout << "Edit Line:" << endl;
    cout << line + 1;
    if((line >= 0) && (line < 10))
        cout << "    ";
    else if((line > 9) && (line < 100))
        cout << "   ";
    else if((line > 99) && (line < 1000))
        cout << "  ";
    else if(line > 999)
        cout << " ";
    document[0].retrieveAt(line,s);
    cout << s << endl << endl;
    cout << "Input new line" << endl;
    cout << ":    ";
    cin.ignore(80, '\n');    
    cin.get(c, 75);
    cin.ignore(80, '\n');
    //strcpy(s,c);
    document[0].replaceAt(line,(string)c);
}

void lineEdit::cls(){
    for(int x = 0; x < 24; x++)
        cout << endl;
}    

const arrayStringListType lineEdit::getDocument(){
    return arrayStringListType(document[0]);
}    

void lineEdit::initializeNew(){
    string s = " ";
    for(int x = 0; x < maxLines; x++)
        document[0].insertEnd(s);
}    
