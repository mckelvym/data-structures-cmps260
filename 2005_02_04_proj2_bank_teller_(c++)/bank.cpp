//  Author        : Mark McKelvy
//  CLID          : jmm0468
//  Class         : CMPS 260 Section 3
//  Assignment    : Programming Assignment 2
//  Date Assigned : 2005, February 4
//  Due Date      : 2005, February 20
//  Due Time      : 10:00 PM
//
//  Program Description: This program represents a bank with an
//    automatic teller. The teller handles user bank accounts, 
//    allowing users to login to their accounts and view the
//    balance, deposit, withdraw. The auto teller also allows
//    users to create new accounts, provided there is enough 
//    room to do so.
//  
//  --* Certification of Authenticity *--
//  I certify that this assignment is entirely my own work.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "account.h"
#include "teller.h"

using namespace std;

// represents the total number of bank accounts available
const int TOTAL_ACCOUNTS = 5;

// pre:  passed an array of accounts
// post: allows the user to begin using the automatic teller
//       or exit the program (at which time all accounts' data
//       is saved to a file)
void menu(account bankAccounts[]);
// pre:  passed a non-null input filestream object and an array of
//       accounts
// post: reads in the data from the file and re-initializes
//       all of the accounts' data
void readInData(ifstream& fin, account bankAccounts[]);
// pre:  passed an output filestream object and an array of
//       accounts
// post: writes all of the data from the accounts to a file
void saveData(ofstream& fout, account bankAccounts[]);

int main(){
    ifstream fin;
    account bankAccounts[TOTAL_ACCOUNTS];
    
    // try to open the specified file, and if it exists (not null)
    // reads in the data to the accounts
    fin.open("data.dat", ios::in);
    if(fin != NULL)
        readInData(fin, bankAccounts);
    fin.close();
    // transfers control to the main menu
    menu(bankAccounts);
    return 0;    
}

void menu(account bankAccounts[]){
     char choice;
     teller Teller(TOTAL_ACCOUNTS);
     
     system("cls");
     cout << endl << "1. Teller Options";
     cout << endl << "0. Exit";
     cout << endl << endl << "Choice: ";
     cin >> choice;
     switch(choice){
                    case '0':
                            char temp;
                            system("cls");
                            cout << "Are you sure you want to exit? ";
                            cin >> temp;
                            if((temp == 'y') || (temp == 'Y')){
                                ofstream fout;
                                fout.open("data.dat", ios::out);
                                saveData(fout, bankAccounts);
                                fout.close();
                            }
                            else menu(bankAccounts);
                            exit(0);
                            break;
                    case '1':
                            Teller.menu(bankAccounts);
                            menu(bankAccounts);
                            break;
     }
}
void readInData(ifstream& fin, account bankAccounts[]){
     long a;
     int b;
     double c;
     for(int x = 0; x < TOTAL_ACCOUNTS; x++){
             fin >> a >> b >> c;
             bankAccounts[x].setAccountNumber(a);
             bankAccounts[x].setPassword(b);
             bankAccounts[x].setBalance(c);             
     }
}
void saveData(ofstream& fout, account bankAccounts[]){
     for(int x = 0; x < TOTAL_ACCOUNTS; x++){
             fout << bankAccounts[x].getAccountNumber() << " " 
                  << bankAccounts[x].getPassword() << " "
                  << bankAccounts[x].getBalance() << endl;
     }
}
