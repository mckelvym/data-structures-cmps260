// jmm0468
// cs260 - 3
// 2005 02 28
// overloading excercise

// ovclass.h

#ifndef _OVCLASS
#define _OVCLASS

#include<iostream>

using namespace std;

const int MAX = 3;

class OvClass
{
    friend istream & operator>>(istream & in, OvClass & object);
    friend ostream & operator<<(ostream & out, OvClass & object);
public:
    OvClass();
    OvClass(int initA, float initB, int x, int y, int z);
    bool operator==(OvClass & another);
    bool operator>=(OvClass & another);
    const OvClass & operator=(const OvClass &);
private:
    int a;
    float b;
    int c[MAX];
};


#endif
