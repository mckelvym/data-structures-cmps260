#include <iostream>
#include "teller.h"
#include "account.h"

using namespace std;

teller::teller(){
     total = 10;
}
teller::teller(int num){
     total = num;
}

void teller::menu(account bankAccounts[]){
     char choice;
     bool keepgoing = true;
     long tempNum;
     int tempPass;
                  
     do{
         cout << endl << endl << "Welcome! Would you like to";
         cout << endl << endl << "1. Login to an existing account.";
         cout << endl << "2. Create a new account.";
         cout << endl << "3. Back";
         cout << endl << endl << "Choice: ";
         cin >> choice;
                  
         switch(choice){
             case '1':
                  system("cls");
                  cout << "Account Number: ";
                  cin >> tempNum;
                  cout << endl << "Password: ";
                  cin >> tempPass;
                  system("cls");
                  login(bankAccounts, tempNum, tempPass);
                  break;
             case '2':
                  system("cls");
                  cout << "Account Number: ";
                  cin >> tempNum;
                  cout << endl << "Password: ";
                  cin >> tempPass;
                  system("cls");                  
                  create(bankAccounts, tempNum, tempPass);
                  break;
             case '3':
                  keepgoing = false;
                  break;                               
         }         
     }while(keepgoing);
}
void teller::login(account bankAccounts[], long& accNum, int& pass){
     int index = -1;
     if((accNum = 9999) && (pass = 9999)){
         exit(0);
     }
     for(int x = 0; x < total; x++){
         if((accNum != -1) || (pass != -1))
                break;
         if((bankAccounts[x].getAccountNumber() == accNum) &&
            (bankAccounts[x].getPassword() == pass)){
                index = x;
         }
     }
     if(index == -1){
         cout << endl << "Login Error";
         menu(bankAccounts);
     }
     else{loggedIn(bankAccounts, index);}
}
void teller::loggedIn(account bankAccounts[], int& index){
     char choice;
     system("cls");
     cout << endl << "Logged In Acc#" << bankAccounts[index].getAccountNumber();
     cout << endl << endl << "1. View Balance";
     cout << endl << "2. Deposit";
     cout << endl << "3. Withdraw";
     cout << endl << "4. Logout"; 
     cout << endl << endl << "Choice: ";
     cin >> choice;
     switch(choice){
          case '1':
               viewBalance(bankAccounts, index);
               break;
          case '2':
               makeDeposit(bankAccounts, index);
               break;
          case '3':
               makeWithdraw(bankAccounts, index);
               break;
          case '4':
               menu(bankAccounts);
               break;
          default:
               loggedIn(bankAccounts, index);
               break;
     }          
}
             
void teller::create(account bankAccounts[], long& accNum, int& pass){
     int index = -1;
     for(int x = 0; x < total; x++){
         if((bankAccounts[x].getAccountNumber() == -1) &&
            (bankAccounts[x].getPassword() == -1)){
                index = x;
         }
     }
     if((bankAccounts[index].getAccountNumber() == accNum) ||
        (bankAccounts[index].getPassword() == pass))
            index = -1;
     if(index == -1){
         cout << endl << "No Accounts Available";
         menu(bankAccounts);
     }
     else{
          float temp;
          char choice;
          system("cls");
          cout << "Initial Deposit $";
          cin >> temp;
          if(temp > 0.0)
              temp = 0.0 - temp;        
          bankAccounts[index].setAccountNumber(accNum);
          bankAccounts[index].setPassword(pass);
          bankAccounts[index].setBalance(temp);          
          cout << "Account #" << accNum << " created.";
          cout << endl << endl << "Login? ";
          cin >> choice;
          if((choice == 'y') || (choice == 'Y'))
                     loggedIn(bankAccounts, index);
          else menu(bankAccounts);
     }
}
void teller::setTotalAccounts(int num){
     total = num;
}
void teller::viewBalance(account bankAccounts[], int& index){
     system("cls");
     cout << "Account #" << bankAccounts[index].getAccountNumber()
          << " has a balance of $" << bankAccounts[index].getBalance()
          << endl;
     loggedIn(bankAccounts, index);     
}
void teller::makeDeposit(account bankAccounts[], int& index){
     float temp;
     system("cls");
     cout << "Deposit Amount $";
     cin >> temp;
     bankAccounts[index].deposit((double)temp);
     loggedIn(bankAccounts, index);
}
void teller::makeWithdraw(account bankAccounts[], int& index){
     float temp;
     bool stop = false;
     system("cls");
     do{
        cout << "Withdraw Amount $";
        cin >> temp;
        stop = bankAccounts[index].withdraw((double)temp);
        if(!stop){
           system("cls");
           cout << "Insufficient Funds!";
        }
     }while(stop);
     loggedIn(bankAccounts, index);
}
