// jmm0468
// cmps260 s3
// employee.h

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<iostream>

using namespace std;

class employee{
// pre:  
//	* passed a reference to an ostream object
//	* passed a reference to an employee object
// post: 
//	* prints the ID, salary, and jobcode of the employee
//	  object, separated by carrage returns
//	* returns an ostream object reference
    friend ostream & operator<<(ostream & out, employee & e);
// pre: 
//	* passed a reference to an istream object
//	* passed a reference to an employee object
// post: 
//	* puts information from the input stream into the
//	  ID, salary, and jobcode of the employee
//	* returns an istream object reference
    friend istream & operator>>(istream & in, employee & e);
    
    public:
// post: 
//	* initializes an employee object: ID = 0, salary = 0, jobCode = -1
        employee();
// pre:  
//	* passed an integer representing Id
//	* passed an integer representing salary
//	* passed an integer representing job code
// post: 
//	* initializes an employee object: ID = Id, salary = sal, jobCode = job
        employee(int Id, int sal, int job);
        
        // accessor functions
// post: 
//	* returns the employee ID
        int getID();
// post: 
//	* returns the employee salary
        int getSalary();
// post: 
//	* returns the employee job code
        int getJobCode();
        
        // modifier functions
// pre:  
//	* passed an integer representing ID
// post: 
//	* returns true
        bool setID(int Id);
// pre:  
//	* passed an integer representing salary
// post: 
//	* returns true
        bool setSalary(int sal);
// pre:  
//	* passed an integer representing job code
// post: 
//	* returns true
        bool setJobCode(int job);
        
// pre: 
//	* compares two employees for equality
// post: 
//	* returns true if the employees have the same 
//	  ID, salary, and job code
        bool operator==(const employee & e) const;
// pre:  
//	* compares two employees for inequality
// post: 
//	* returns false if the employees have the same
//	  ID, salary, and job code
        bool operator!=(const employee & e) const;
// pre: 
//	* compares two employees for less than or equal to
// post: 
//	* returns true if employees have the same jobcode and
//	  if the first salary is less than or equal to the second
        bool operator<=(const employee & e) const;
// pre: 
//	* compares two employees for greater than or equal to
// post: 
//	* returns true if employees have the same jobcode and
//	  if the first salary is greater than or equal to the second
        bool operator>=(const employee & e) const;
// pre: 
//	* compares two employees for less than
// post: 
//	* returns true if employees have the same jobcode and
//	  if the first salary is less than the second
        bool operator<(const employee & e) const;
// pre: 
//	* compares two employees for greater than
// post: 
//	* returns true if employees have the same jobcode and
//	  if the first salary is greater than the second
        bool operator>(const employee & e) const;
    
// pre:  
//	* assignment operator
// post: 
//	* if the first object is not the same as the second object
//	  then the first object is assigned the value of the second
        const employee & operator=(const employee &);

    private:
// represents the employee ID
  	int ID;
// represents the employee salary
    	int salary;
// represents the employee job code
    	int jobCode;	
};

#endif
