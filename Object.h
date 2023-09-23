#pragma once
#include <iostream>
#include <string>
using namespace std;
class Object
{	
public:    
	virtual bool equals(Object*) = 0;
	virtual string toString() = 0;
	virtual void copy(Object*) = 0;
	
};

