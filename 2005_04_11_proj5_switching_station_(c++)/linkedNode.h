//Header File: linkedNode.h

#ifndef H_LINKEDNODE
#define H_LINKEDNODE

using namespace std;

//Definition of the node
template <class Type>
struct nodeType
{
	Type dest;
	Type id;
	nodeType<Type> *next;
};

#endif
