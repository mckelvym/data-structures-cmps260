#include <iostream>
#include <fstream>
#include <string>
//#include <conio.h>
#include<cstdio>

using namespace std;

const int maxLength = 30;

struct node{
    char key[maxLength];
    char value[maxLength];
    node * next;
};

node * head = NULL;
node * current = NULL;

void open();
void readData(char file[maxLength]);
void write();
node * newNode(char value[maxLength]); 
void insert(node * temp);
void genKey(char key[maxLength], char value[maxLength]);
void pK(string before, node * n, string after);
void pV(string before, node * n, string after);
void wV(ofstream & fout, string before, node * n, string after);
void printAllValues();
void writeAllValues(char file[maxLength]);
int findLength(char temp[maxLength]);
char toLower(char c);
void cls();
void fix();
void fixFile(char sfile[maxLength], char ofile[maxLength]);

int main(void){
    char choice[maxLength];
    
    while(true){
        cls();
        cout << "  * Mr. Anagram *" << endl << endl;
        cout << " o - (O)pen File" << endl;
        cout << " f - (F)ix File to Lowercase" << endl;
        cout << " d - (D)isplay Anagrams" << endl;
        cout << " w - (W)rite Anagrams to File" << endl;
        cout << " x - E(x)it" << endl << endl;
        cout << "> ";
        cin >> choice;
        choice[0] = toLower(choice[0]);
        switch(choice[0]){
            case 'o':
                open();
                break;
            case 'f':
                fix();
                break;
            case 'd':
                char t[30];
                printAllValues();
                cout << endl << "Type any character + [ENTER] to continue: ";
                cin >> t;
                break;
            case 'w':
                write();
                break;
            case 'x':
                exit(0);
                break;                
            default:
                break;
        }
    }
    
    
    
    return 0;
}

void open(){
    char temp[maxLength];
    
    cls();
    cout << " Filename" << endl << endl << "> ";
    cin >> temp;
    readData(temp);
}

void readData(char file[maxLength]){
    char temp[maxLength];
    ifstream fin;
    node * temp_node;
    
    head = NULL;
    fin.open(file);
    while(!fin.eof()){
        fin >> temp;
        temp_node = newNode(temp);
        cout << temp << endl;
        insert(temp_node);
    }
}

void write(){
    char temp[maxLength];

    cls();
    if(head != NULL){
        cout << " Filename" << endl << endl << "> ";
        cin >> temp;
        writeAllValues(temp);
    }
    else{
        cout << " ** No Data **" << endl;
        cout << "Return ";
        cin >> temp;
    }
}            
    

node * newNode(char value[maxLength]){
    node * temp = new node;
    
    strcpy(temp->value,value);
    genKey(temp->key, value);
    temp->next = NULL;
    return temp;
}

void insert(node * temp){
    if(head != NULL){
        if(true && (strcmp(temp->key,head->key) < 1)){
            temp->next = head;
            head = temp;
            temp = head->next;
            current = temp;
        }
        else 
            current = head;
        while((current->next != NULL) && (strcmp(temp->key,current->next->key) > -1))
            current = current->next;
        if(current != temp){
            temp->next = current->next;
    	    current->next = temp;
        }
    }
    else
        head = temp;                  
}

void genKey(char key[maxLength], char value[maxLength]){
    int temp;
    int max = findLength(value);
    bool swap = false;
    char tempArray[maxLength];
    
    strcpy(tempArray,value);    
    for(int x = 0; x < max; x++){
        swap = false;
        temp = x;
        for(int y = (x + 1); y < max; y++){
            if(tempArray[temp] > tempArray[y]){
                temp = y;
                swap = true;
            }
        }
        if(swap){
            char temp_char = tempArray[x];
            tempArray[x] = tempArray[temp];
            tempArray[temp] = temp_char;
        }
    }    
    strcpy(key,tempArray);
}

void pK(string before, node * n, string after){
    cout << before << n->key << after;
}

void pV(string before, node * n, string after){
    cout << before << n->value << after;
}

void wV(ofstream & fout, string before, node * n, string after){
    fout << before << n->value << after;
}    

void printAllValues(){
    if(head != NULL){
        current = head;
        while(current != NULL){
            pV(" ", current, "\n");
            current = current->next;
        }
    }
    else{
        cout << " ** No Data **" << endl;
    }        
}

void writeAllValues(char file[maxLength]){
    ofstream fout;
    if(head != NULL){
        fout.open(file);
        current = head;
        while(current != NULL){
            wV(fout, "", current, "\n");
            current = current->next;
        }
    }
}   

int findLength(char temp[maxLength]){
    int length = 0;
    
    while(temp[length] != '\0')
        length++;
    return length;
}

char toLower(char c){
    if((c >= 65) && (c <= 90))
        c += 32;
    return c;
}

void cls(){
    for(int x = 0; x < 25; x++)
        cout << endl;
}

void fix(){    
    char sfile[maxLength];
    char ofile[maxLength];

    cls();
    do{
        cout << " Source Filename" << endl << endl << "> ";
        cin >> sfile;
        cout << endl << " Output Filename" << endl << endl << "> ";
        cin >> ofile;
        if(strcmp(sfile,ofile) == 0)
            cout << endl << " ** Invalid Filenames ** " << endl;
    }while(strcmp(sfile,ofile) == 0);                
    fixFile(sfile,ofile);
}

void fixFile(char sfile[maxLength], char ofile[maxLength]){
    char temp[maxLength];
    ifstream fin;
    ofstream fout;
    
    fin.open(sfile);
    fout.open(ofile);
    while(!fin.eof()){
        fin >> temp;
        for(int x = 0; x < findLength(temp); x++)
                temp[x] = toLower(temp[x]);
        if(fin.eof())
                fout << temp;
        else fout << temp << endl;
    }
    fin.close();
    fout.close();        
}
