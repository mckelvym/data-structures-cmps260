#ifndef _account_h
#define _account_h

// this class represents a customer bank account
class account{
      public:
             // constructors
             
             // pre:  default constructor for an account
             // post: creates an account with account number -1,
             //       password -1, and balance 0
             account();
             // pre:  parameterized constructor for an account,
             //       passed an account number and password
             // post: creates an account with the account number passed,
             //       the password passed, and balance 0
             account(long accNum, int pass);
             // pre:  parameterized constructor for an account,
             //       passed an account number and password,
             //       as well as a starting balance
             // post: creates an account with the account number passed,
             //       the password passed, and the balance passed
             account(long accNum, int pass, double startBal);
             
             // modifiers
             
             // pre:  passed an account number (name)
             // post: changes the account number
             void setAccountNumber(const long&);
             // pre:  passed an account password
             // post: changes the account password
             void setPassword(const int&);
             // pre:  passed an account balance
             // post: changes the balance if >= 0
             void setBalance(const double&);
             // post: returns the account number
             long getAccountNumber();
             // post: returns the account password
             int getPassword();
             // post: returns the account balance
             double getBalance();
             // pre:  passed a number to add to the 
             //       account balance
             // post: adds (deposits) the number into
             //       the account balance
             void deposit(const double&);
             // pre:  passed a number to subtract from the
             //       account balance
             // post: subtracts (withdraws) the number from the account
             //       balance if the resulting balance is greater 
             //       than zero, and returns true, else, nothing
             //       is done and false is returned
             bool withdraw(const double&);
             
      private:
              // represents the account number (name)
              long accountNumber;
              // represents the account password
              int password;
              // represents the balance of the account
              double balance;
};

#endif
