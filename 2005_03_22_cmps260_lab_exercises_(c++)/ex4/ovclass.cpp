// jmm0468
// cs260 - 3
// 2005 02 28
// overloading excercise

// ovclass.cpp

#include "ovclass.h"

using namespace std;

OvClass::OvClass()
{
    a = 0;
    b = 0;
    c[0] = 0;
    c[1] = 0;
    c[2] = 0;
}


OvClass::OvClass(int initA, float initB, int x, int y, int z)
{ 
    a = initA;
    b = initB;
    c[0] = x;
    c[1] = y;
    c[2] = z;
}

bool OvClass::operator==(OvClass & another){
	if(a == another.a 
	&& b == another.b
	&& c[0] == another.c[0]
	&& c[1] == another.c[1]
	&& c[2] == another.c[2]){
		return true;
	}
	else{
		return false;
	}
}

bool OvClass::operator>=(OvClass & another){
	if(a >= another.a 
	&& b >= another.b
	&& c[0] >= another.c[0]
	&& c[1] >= another.c[1]
	&& c[2] >= another.c[2]){
		return true;
	}
	else{
		return false;
	}
}

istream & operator>>(istream & in, OvClass & object){
	in >> object.a >> object.b >> object.c[0] >> object.c[1] >> object.c[2];
	return in;
}

ostream & operator<<(ostream & out, OvClass & object){
	out << object.a << ' '
	    << object.b << ' '
	    << object.c[0] << ' '
	    << object.c[1] << ' '
	    << object.c[2] << endl;
	return out;
}

const OvClass & OvClass::operator=(const OvClass & object){
	if(this != &object){
		a = object.a;
		b = object.b;
		for(int x = 0; x < MAX; x++){
			c[x] = object.c[x];
		}
	}
	return *this;
}
	
