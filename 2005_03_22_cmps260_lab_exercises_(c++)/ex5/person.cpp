#include <iostream>
#include <string>
#include "person.h"
using namespace std;

Person::Person()
{
    name = "";
    height = 0;
    weight = 0;
}

Person::Person(string name, int height, int weight)
{
    this->name = name;
    this->height = height;
    this->weight = weight;
}

string Person::getName()
{
    return name;
}

int Person::getHeight()
{
    return height;
}

int Person::getWeight()
{
    return weight;
}






bool Person::operator==(const Person & a) const
{
    if (name == a.name)
        return true;
    return false;
}

bool Person::operator!=(const Person & a) const 
{
    if (name != a.name)
        return true;
    return false;
}

bool Person::operator>=(const Person & a) const 
{
    if (name >= a.name)
        return true;
    return false;
}

bool Person::operator<=(const Person & a) const 
{
    if (name <= a.name)
        return true;
    return false;
}

bool Person::operator<(const Person & a) const 
{
    if (name < a.name)
        return true;
    return false;
}

bool Person::operator>(const Person & a) const 
{
    if (name > a.name)
        return true;
    return false;
}





const Person & Person::operator=(const Person & a) 
{   
    name = a.name;
    height = a.height;
    weight = a.weight;
        
    return *this;
}





ostream & operator<<(ostream & out, Person & a)
{
    out << a.name << endl
        << a.height << endl
	<< a.weight << endl;

    return out;
}

istream & operator>>(istream & in, Person & a)
{
    string dummy;
    
    getline(in, a.name);
    in >> a.height >> a.weight;
    getline(in,dummy);
    
    return in;
}

