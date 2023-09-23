#pragma once
#include "Object.h"
class Integer :
    public Object
{
public:
    int elemento;
    virtual string toString() override;
    virtual bool equals(Object*) override;
    virtual void copy(Object*) override;
    Integer(int x = 0);
    
};

