// jmm0468
// cs260 - 3
// 2005 02 28
// overloading excercise

// test.cpp

#include <iostream>
#include <fstream>
#include "ovclass.h"
using namespace std;

int main()
{
    ifstream in;
    ofstream out;
    OvClass e;
    OvClass f(2,2.2, 11, 12, 13);
    OvClass g(9,3.3, 22, 33, 44);
    
    in.open("data.dat");
    out.open("data2.dat");
    if(!in){
    	cout << "no input file" << endl;
	exit(0);
    }
    else{
    	do{
		in >> e;
		cout << e;
		out << e;
	}while(!in.eof());
    }
    in.close();
    out.close();
    
    if(f == g)
    	cout << "f = g is true";
    else
    	cout << "f = g is false";
    cout << endl;
    if(g >= f)
    	cout << "g >= f is true";
    else
    	cout << "g >= f is false";
    cout << endl;
    e = g;
    cout << "e = " << e;
    cout << "g = " << g;
    
    return 0;
}
