//  Author        : Mark McKelvy
//  CLID          : jmm0468
//  Class         : CMPS 260 - 3
//  Assignment    : Programming Assignment 4
//  Date Assigned : 2005, March 14
//  Due Date      : 2005, April 3
//  Due Time      : 10:00 PM
//
//  Program Description: This program is an accounting program used
//	for computerized records of a firms employees. The program
//	loads, stores, and manipulates information about employees
//	stored in the payrole file, and references a jobs file for
//	the description of various jobs 
//  
//  --* Certification of Authenticity *--
//  I certify that this assignment is entirely my own work.

// main.cpp

#include<iostream>
#include<fstream>
#include<string>
#include "employee.h"
#include "arrayListType.h"

using namespace std;

// maximum number of job types
const int MAX_JOBS = 10;
// maximum number of employees allowed
const int MAX_EMPLOYEES = 200;
// name of file containing job descriptions
const char JOBS_FILE[] = "jobs.dat";
// name of file containing employee payrole
const char PAYROLE_FILE[] = "payrole.dat";

// pre:   
//      * passed array of strings representing the job descriptions
// post: 
//	* reads data from the file specified by the constant JOBS_FILE
//	  and puts it into the jobDescriptions array
void readJobs(string jobDescriptions[]);
// pre:   
//      * passed an object of arrayListType<employee> representing
//        all employees in the system
// post: 
//	* reads data from the file specified by the constant PAYROLE_FILE
//	  and puts it into the employees object
void readEmployees(arrayListType<employee> & employees);
// pre:   
//      * passed an object of arrayListType<employee> representing
//        all employees in the system
// post: 
//	* saves data to the file specified by the constant PAYROLE_FILE
//	  from the employees object
void saveEmployees(arrayListType<employee> & employees);
// pre:   
//      * passed an object of arrayListType<employee> representing
//        all employees in the system
//      * passed array of strings representing the job descriptions
// post: 
//	* prints information on a specific employee, based on ID
void printEmployee(arrayListType<employee> & employees, string jobDescriptions[]);
// pre:   
//      * passed an object of arrayListType<employee> representing
//        all employees in the system
//      * passed array of strings representing the job descriptions
// post: 
//	* prints information on all employees, pausing every 20 employees
void printEmployees(arrayListType<employee> & employees, string jobDescriptions[]);
// pre:   
//      * passed an object of arrayListType<employee> representing
//        all employees in the system
//      * passed array of strings representing the job descriptions
// post: 
//	* adjusts the salary of a specific employee
void setSalary(arrayListType<employee> & employees, string jobDescriptions[]);
// pre:   
//      * passed an object of arrayListType<employee> representing
//        all employees in the system
//      * passed array of strings representing the job descriptions
// post: 
//	* changes the job code of a specific employee
void setJobCode(arrayListType<employee> & employees, string jobDescriptions[]);
// pre:   
//      * passed an object of arrayListType<employee> representing
//        all employees in the system
// post: 
//	* removes an employee based on ID if the user confirms to do so
void remove(arrayListType<employee> & employees);
// pre:   
//      * passed an object of arrayListType<employee> representing
//        all employees in the system
//      * passed array of strings representing the job descriptions
// post: 
//	* gathers data to create a new employee entry, and passes the 
//	  data to the insert method
void add(arrayListType<employee> & employees, string jobDescriptions[]);
// pre:   
//      * passed an object of arrayListType<employee> representing
//        all employees in the system
//      * passed integer representing an employee ID
//      * passed integer representing an employee salary
//      * passed integer representing an employee job code
// post: 
//      * adds a new employee to the employees object
void insert(arrayListType<employee> & employees, int ID, int salary, int jobCode);
// pre:   
//      * passed integer representing the number of tabs to print
// post: 
//      * prints the number of tab spaces specified
string tabs(int n);
// pre:   
//      * passed character to convert to lowercase if needed
// post:
//      * returns a lowercase letter 
char fixChoice(char c);
// post: 
//      * clears the screen
void cls();
// post: 
//      * prompts the user to proceed
//      * returns true if yes, false if no
bool getch();

int main(){
    char choice = 'x';
    employee e;
    string jobDescriptions[MAX_JOBS];
    arrayListType<employee> employees(MAX_EMPLOYEES);
   
    readJobs(jobDescriptions);
    readEmployees(employees);
    
    do{
    	cout << endl << endl;
    	cout << " * MAIN MENU *" << endl << endl;
    	cout << "n - (N)ew" << endl;
    	cout << "s - Adjust (S)alary" << endl;
    	cout << "c - (C)hange Job" << endl;
    	cout << "p - (P)rint Single" << endl;
    	cout << "a - Print (A)ll" << endl;
    	cout << "r - (R)emove" << endl;
    	cout << "x - E(x)it" << endl;
    	cout << endl << "> ";
    	cin >> choice;
    	choice = fixChoice(choice);
    	switch(choice){
    		case 'n':
                	add(employees, jobDescriptions);
    			break;
    		case 's':
                	setSalary(employees, jobDescriptions);
    			break;
    		case 'c':
                	setJobCode(employees, jobDescriptions);
    			break;
    		case 'p':
                	printEmployee(employees, jobDescriptions);
    			break;
    		case 'a':
                	printEmployees(employees, jobDescriptions);
    			break;
    		case 'r':
                	remove(employees);
    			break;
    		case 'x':
                	break;
                default:
                	cls();
                	cout << endl << " *** OPTION NOT VALID ***";
                	break;
    	}
    }while(choice != 'x');
    
    saveEmployees(employees);
    
    return 0;
}

void readJobs(string jobDescriptions[]){
    ifstream fin;
    
    fin.open(JOBS_FILE);
    for(int x = 0; x < MAX_JOBS; x++)
        fin >> jobDescriptions[x];
    fin.close();
}

void readEmployees(arrayListType<employee> & employees){
    employee e;
    ifstream fin;
    
    int temp;
    
    fin.open(PAYROLE_FILE);
    while(!fin.eof()){
    	fin >> e;
        employees.insert(e);
    }
    fin.close();
}

void saveEmployees(arrayListType<employee> & employees){
    int length = employees.listSize();
    employee e;
    ofstream fout;
    
    fout.open(PAYROLE_FILE);    
    for(int x = 0; x < length; x++){
        employees.retrieveAt(x, e);
        fout << e << endl;
    }
    fout.close();
}

void printEmployee(arrayListType<employee> & employees, string jobDescriptions[]){
    bool found = false;
    int counter = 0;
    int length = employees.listSize();
    int ID = 0;
    employee e;
    
    cls();
    cout << " ** EMPLOYEE INFO **" << endl << endl;
    cout << "ID: ";
    cin >> ID;
    while(!found && counter <= length){
    	employees.retrieveAt(counter, e);
    	if(e.getID() == ID)
    		found = true;
        else counter++;
    }
    cout << endl;
    if(found){
    	if((e.getJobCode() < 0) || (e.getJobCode() >= MAX_JOBS)){
        	cout << " *** ERROR: INCORRECT JOBCODE ***" << endl;
    	}
    	else{
        	cout << "Salary: $" << e.getSalary() << endl;
        	cout << "Job: " << jobDescriptions[e.getJobCode()] << endl;
    	}
    }
    else{
    	cout << " *** ERROR: EMPLOYEE NOT FOUND ***" << endl;
    }
}

void printEmployees(arrayListType<employee> & employees, string jobDescriptions[]){
    int length = employees.listSize();
    employee e;
    
    cls();
    cout << "   --ID--" << tabs(2) << "--SALARY--" << tabs(2) << "--JOB--" << endl;
    for(int x = 0; x < length; x++){
        employees.retrieveAt(x, e);
        if(x < 9)
        	cout << x+1 << ". " << e.getID() << tabs(3) << "$" << e.getSalary() << tabs(3) << jobDescriptions[e.getJobCode()] << ", " << e.getJobCode() << endl;
	else cout << x+1 << ". " << e.getID() << tabs(2) << "$" << e.getSalary() << tabs(3) << jobDescriptions[e.getJobCode()] << ", " << e.getJobCode() << endl;                                                                  
        if((x+1)%20 == 0 && x != 0){
            if(!getch()){
                x = length;
            }
        }
    }
}

void setSalary(arrayListType<employee> & employees, string jobDescriptions[]){
    bool found = false;
    int counter = 0;
    int length = employees.listSize();
    int salary = 0;
    int ID = 0;
    employee e;
    
    cls();
    cout << " ** EMPLOYEE SALARY **" << endl << endl;
    cout << "ID: ";
    cin >> ID;
    while(!found && counter <= length){
    	employees.retrieveAt(counter, e);
    	if(e.getID() == ID)
    		found = true;
        else counter++;
    }
    cout << endl;
    if(found){
    	cout << "Job: " << jobDescriptions[e.getJobCode()] << endl;
    	cout << "Current Salary: $" << e.getSalary() << endl;
    	cout << "New Salary: $";
    	cin >> salary;
    	cout << endl << endl;;
    	if(e.setSalary(salary)){
        	cout << " * SALARY CHANGE SUCCESSFUL *" << endl;
        	employees.replaceAt(counter, e);
        }
    	else
        	cout << " *** ERROR: SALARY CHANGE FAILED ***" << endl;
    }
    else{
    	cout << " *** ERROR: EMPLOYEE NOT FOUND ***" << endl;
    }    
}

void setJobCode(arrayListType<employee> & employees, string jobDescriptions[]){
    bool found = false;
    int counter = 0;
    int length = employees.listSize();
    int jobCode = -1;
    int ID = 0;
    employee e;
    
    cls();
    cout << " ** EMPLOYEE JOB CODE **" << endl << endl;
    cout << "ID: ";
    cin >> ID;
    while(!found && counter <= length){
    	employees.retrieveAt(counter, e);
    	if(e.getID() == ID)
    		found = true;
        else counter++;
    }
    if(found){
    	cls();
    	cout << " ** JOB CODES **" << endl;
    	for(int x = 0; x < MAX_JOBS; x++)
    		cout << x << ". " << jobDescriptions[x] << endl;
    	cout << endl;
    	cout << "Salary: $" << e.getSalary() << endl;
    	cout << "Current Job: " << jobDescriptions[e.getJobCode()] << " Code: " << e.getJobCode() << endl;
    	do{
    		cout << "New Job Code: ";
    		cin >> jobCode;
    		cout << endl;
    		if(jobCode < 0 || jobCode >= MAX_JOBS)
    			cout << " *** ERROR: JOBCODE NOT VALID ***" << endl;
    	}while(jobCode < 0 || jobCode >= MAX_JOBS);
    	if(e.setJobCode(jobCode)){
    		cout << endl << " * JOBCODE CHANGE SUCCESSFUL *" << endl;
    		employees.replaceAt(counter, e);
    	}
    	else
    		cout << endl << " *** ERROR: JOBCODE CHANGE FAILED ***" << endl; 
    }
    else{
    	cout << endl << " *** ERROR: EMPLOYEE NOT FOUND ***" << endl;
    }
}

void remove(arrayListType<employee> & employees){
    bool found = false;
    int counter = 0;
    int length = employees.listSize();
    int ID = 0;
    employee e;
    
    cls();
    cout << " ** REMOVE EMPLOYEE **" << endl << endl;
    cout << "ID: ";
    cin >> ID;
    while(!found && counter <= length){
    	employees.retrieveAt(counter, e);
    	if(e.getID() == ID)
    		found = true;
    	else counter++;
    }
    cout << endl;
    if(found){
    	if(getch()){
    		employees.removeAt(counter);
    		cout << " * EMPLOYEE REMOVED *" << endl;
 	}   
    	else cout << " * EMPLOYEE NOT REMOVED *" << endl;
    }
    else{
    	cout << " *** ERROR: EMPLOYEE NOT FOUND ***" << endl;
    }
}

void add(arrayListType<employee> & employees, string jobDescriptions[]){
    bool found = false;
    int counter = 0;
    int length = employees.listSize();
    int ID = 0;
    int salary = 0;
    int jobCode = -1;
    employee e;
    
    if(length < employees.maxListSize()){
    	cls();
	    cout << " ** ADD EMPLOYEE **" << endl << endl;
    	cout << "ID: ";
    	cin >> ID;
    	while(!found && counter <= length){
    		employees.retrieveAt(counter, e);
    		if(e.getID() == ID)
    			found = true;
    		else counter++;
    	}
    	cout << endl;
    	if(found){
    		cout << " *** ERROR: EMPLOYEE PRESENT ***" << endl;
    	}
    	else{
    		cls();
	    	cout << " ** JOB CODES **" << endl;
    		for(int x = 0; x < MAX_JOBS; x++)
    			cout << x << ". " << jobDescriptions[x] << endl;
	    	cout << endl;
    	    	do{
    			cout << "New Job Code: ";
    			cin >> jobCode;
	    		cout << endl;
    			if(jobCode < 0 || jobCode >= MAX_JOBS)
    				cout << " *** ERROR: JOBCODE NOT VALID ***" << endl;
	    	}while(jobCode < 0 || jobCode >= MAX_JOBS);
		cout << "Salary: $";
    		cin >> salary;
    		cout << endl;
    		insert(employees, ID, salary, jobCode);
    	}
    }
    else{
    	cout << " *** ERROR: LIST IS FULL ***" << endl;
    }
}

void insert(arrayListType<employee> & employees, int ID, int salary, int jobCode){
	employee e(ID, salary, jobCode);
	// add a random insertion method here
	employees.insertEnd(e);
}

string tabs(int n){
    string s;
    for(int x = 0; x < n; x++)
    	s += "\t";
    return s;
}

char fixChoice(char c){
    if((c >= 65) && (c <= 90))
    	c += 32;
    return c;
}

void cls(){
    system("clear");
    //for(int x = 0; x < 25; x++)
    //    cout << endl;
}

bool getch(){
    char choice[30];
    cout << "Proceed (y/n)? ";
    cin >> choice;
    cout << endl;
    if(fixChoice(choice[0]) == 'y')
        return true;
    else return false;
}