#ifndef _PERSON 
#define _PERSON

#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    Person();
    Person(string name, int height, int weight);
    string getName();
    int getHeight();
    int getWeight();
   
    bool operator==(const Person & a) const;
    bool operator!=(const Person & a) const;
    bool operator>=(const Person & a) const;
    bool operator<=(const Person & a) const;
    bool operator<(const Person & a) const;
    bool operator>(const Person & a) const;
    
    const Person & operator=(const Person & a);
    
private:
    string name;
    int height;
    int weight;


friend ostream & operator<<(ostream & out, Person & a);    
friend istream & operator>>(istream & in, Person & a);    
};

#endif
