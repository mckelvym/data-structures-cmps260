// jmm0468
// cmps260 s3
// employee.cpp

#include <iostream>
#include "employee.h"

using namespace std;

employee::employee(){
    ID = 0;
    salary = 0;
    jobCode = -1;
}

employee::employee(int Id, int sal, int job){
    ID = Id;
    salary = sal;
    jobCode = job;
}

int employee::getID(){
    return ID;
}

int employee::getSalary(){
    return salary;
}

int employee::getJobCode(){
    return jobCode;
}

bool employee::setID(int Id){
    ID = Id;
    return true;
}

bool employee::setSalary(int sal){
    salary = sal;
    return true;
}

bool employee::setJobCode(int job){
    jobCode = job;
    return true;
}

ostream & operator<<(ostream & out, employee & e){
    out << e.ID << endl;
    out << e.salary << endl;
    out << e.jobCode << endl;    
    return out;
}

istream & operator>>(istream & in, employee & e){
    in >> e.ID >> e.salary >> e.jobCode;
    return in;
}

bool employee::operator==(const employee & e) const{
    if((ID == e.ID) && (salary == e.salary) && (jobCode == e.jobCode))
        return true;
    else return false;
}

bool employee::operator!=(const employee & e) const{
    if((ID == e.ID) && (salary == e.salary) && (jobCode == e.jobCode))
        return false;
    else return true;
}

bool employee::operator<=(const employee & e) const{
    if((salary <= e.salary) && (jobCode == e.jobCode))
        return true;
    else return false;
}

bool employee::operator>=(const employee & e) const{
    if((salary >= e.salary) && (jobCode == e.jobCode))
        return true;
    else return false;
}

bool employee::operator<(const employee & e) const{
    if((salary < e.salary) && (jobCode == e.jobCode))
        return true;
    else return false;
}

bool employee::operator>(const employee & e) const{
    if((salary > e.salary) && (jobCode == e.jobCode))
        return true;
    else return false;
}

const employee & employee::operator=(const employee & e){
    // make sure that this address is not the same as the one passed
	if (this != &e){
	   salary = e.salary;		   
       jobCode = e.jobCode;			   
       ID = e.ID;
    }
    return *this;					   	   
}
