#pragma once
#include "Object.h"
class Integer :
    public Object
{
public:
    int elemento;
    int getElemento();
    void setElemento(int);
    virtual string toString() override;
    virtual bool equals(Object*) override;
    virtual Object* copy() override;
    Integer(int x = 0);
};

