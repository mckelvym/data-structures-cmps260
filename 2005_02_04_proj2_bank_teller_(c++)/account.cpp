#include "account.h"

using namespace std;

account::account(){
     accountNumber = -1;
     password = -1;
     balance = 0.0;
}
account::account(long accNum, int pass){
     accNum = accountNumber;
     password = pass;
}
account::account(long accNum, int pass, double startBal){
     accNum = accountNumber;
     password = pass;
     if(startBal >= 0.0)
          balance = startBal;
} 
void account::setAccountNumber(const long& number){
     accountNumber = number;
}
void account::setPassword(const int& pass){
     password = pass;
}
void account::setBalance(const double& bal){
     if(bal >= 0.0)
           balance = bal;     
}
long account::getAccountNumber(){
     return accountNumber;
}
int account::getPassword(){
    return password;
}
double account::getBalance(){
       return balance;
}
void account::deposit(const double& dep){
     balance += dep;
}
bool account::withdraw(const double& with){
     double temp = balance - with;
     if(with >= 0.0){
             balance = temp;
             return true;
     }
     else return false;
}

