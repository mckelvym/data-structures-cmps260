#ifndef _teller_h
#define _teller_h

#include "account.h"

class teller{
      public:
	     // constructors

	     // pre:  default constructor
	     // post: creates an automatic teller which is set to 
	     //       handle 10 (bank) accounts
             teller();
	     // pre:  parameterized constructor, passed the number of
	     //       accounts to handle
	     // post: creates an automatic teller which is set to
	     //       handle the number of (bank) accounts passed
             teller(int num);
	     // pre:  default automatic teller menu is passed an array
	     //       of accounts.
	     // post: displays a menu to the user which directs the user 
	     //       to either set up a new account or login to an
	     //       existing account, and calls the appropriate
	     //       helper function
             void menu(account bankAccounts[]);
	     // pre:  passed an array of accounts, an account number, 
	     //       and a password to login to an account
	     // post: if the correct account number and password are 
	     //       supplied, data about the account is accessed
	     //       using helper functions. If account number '9999'
	     //       and password '9999' are entered, the program quits.
	     //       If the username and password are incorrect, 
	     //       the program goes back to the main teller
             void login(account bankAccounts[], long& accNum, int& pass);
	     // pre:  passed an array of accounts, and the specific
	     //       index of the account to look at (user is logged
	     //       in already)
	     // post: allows the user to view balance, deposit into the
	     //       account, withdraw from the account, or logout.
	     //       A deposit will add the absolute value of the number
	     //       entered. A withdraw must not exceed the number of
	     //       funds in the account or else it will be denied. 
	     //       Logout takes the user to the teller menu.
             void loggedIn(account bankAccounts[], int& index);
	     // pre:  allows the user to create a new account
	     // post: if there is at least one available. If there not one
	     //       available then the user is denied creation of a new 
	     //       account. If an account is available, an initial deposit 
	     //       > 0 will only be allowed. After creating an account, the 
	     //       user will be asked to login, or may return to the main
	     //       teller menu
             void create(account bankAccounts[], long& accNum, int& pass);
	     // pre:  passed a number to set the total number of accounts
	     //       that the automatic teller will handle
             void setTotalAccounts(int num);
	     // pre:  passed an array of accounts, and the index of the
	     //       specific account being dealt with
	     // post: displays the balance of a user account, then goes
	     //       back to the logged in menu
             void viewBalance(account bankAccounts[], int& index);
	     // pre:  passed an array of accounts, and the index of the
	     //       specific account being dealt with
	     // post: asks the user for an amount to deposit, and makes
	     //       the appropriate addition to the account balance	     
             void makeDeposit(account bankAccounts[], int& index);
	     // pre:  passed an array of accounts, and the index of the
	     //       specific account being dealt with
	     // post: asks the user for an amount to withdraw, and if
	     //       the withdraw does not exceed the balance in the 
	     //       account, makes the appropriate subtraction to
	     //       the account balance, otherwise, the withdraw
	     //       is not allowed
             void makeWithdraw(account bankAccounts[], int& index);
      private:
	     // represents the total number of accounts that the 
	     // automatic teller will be handling
             int total;
};

#endif
